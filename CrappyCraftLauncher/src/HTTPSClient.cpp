#include "HTTPSClient.h"
#include "Log.h"
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/thread.hpp>
#include <boost/function.hpp>
#include <boost/lexical_cast.hpp>
#include <string>

using namespace boost::asio;

HTTPSClient::HTTPSClient() : mResponseStream(&mResponse)
{
    ssl::context context(ssl::context::sslv23);
    context.set_verify_mode(ssl::verify_peer);
    context.set_default_verify_paths();
    context.load_verify_file("mojang.pem");
    mpSSLSocket = new ssl::stream<ip::tcp::socket>(mIOService, context);
}

HTTPSResult HTTPSClient::SendHTTPSRequest(const boost::property_tree::ptree &crPTree,
    const std::string cHost, const std::string cURI)
{
    LOG_DEBUG("Resolving " + cHost);
    mPTreeRequest = crPTree;
    mHost = cHost;
    mURI = cURI;

    // Resolve the Minecraft authentication server name
    ip::tcp::resolver::iterator tcpEndpointIterator;
    try
    {
        // Resolve the host
        ip::tcp::resolver tcpResolver(mIOService);
        ip::tcp::resolver::query tcpResolverQuery(cHost, "https");
        tcpResolver.async_resolve(tcpResolverQuery, boost::bind(&HTTPSClient::HandleResolve, this, 
            placeholders::error, placeholders::iterator));
        
        mIOService.run();
        LOG_DEBUG("mIOService returned");
    }
    catch (boost::system::system_error ex)
    {
        LOG_ERROR(ex.what());
        std::cin.get();
    }
    catch (std::exception ex)
    {
        LOG_ERROR(ex.what());
        std::cin.get();
    }

    return mHTTPSResult;
}

void HTTPSClient::HandleResolve(const boost::system::error_code &crError,
    const ip::tcp::resolver::iterator &criEndpoints)
{
    if (crError)
    {
        LOG_ERROR("Failed to resolve host " + mHost);
        std::cin.get();
        return;
    }

    // Connect to the first endpoint we can connect with
    async_connect(mpSSLSocket->lowest_layer(), criEndpoints,
        boost::bind(&HTTPSClient::HandleConnect, this, placeholders::error));
}

void HTTPSClient::HandleConnect(const boost::system::error_code &crError)
{
    if (crError)
    {
        LOG_ERROR("Failed to connect to host");
        std::cin.get();
        return;
    }

#ifdef _DEBUG
    char port[6];
    _itoa_s(mpSSLSocket->lowest_layer().remote_endpoint().port(), port, 10);
    LOG_DEBUG("Connected to " + mpSSLSocket->lowest_layer().remote_endpoint().address().to_string()
        + std::string(":") + port);
#endif

    mpSSLSocket->lowest_layer().set_option(ip::tcp::no_delay(true));
    mpSSLSocket->set_verify_callback(ssl::rfc2818_verification(mHost));

    // Perform a handshake
    LOG_DEBUG("Performing SSL handshake");
    mpSSLSocket->async_handshake(ssl::stream_base::client, 
        boost::bind(&HTTPSClient::HandleHandshake, this, placeholders::error));
}

void HTTPSClient::HandleHandshake(const boost::system::error_code &crError)
{
    if (crError)
    {
        LOG_ERROR("Failed to perform SSL handshake");
        std::cin.get();
        return;
    }

    LOG_DEBUG("SSL handshake successful!");

    // Write the json into a stringstream
    std::ostringstream json;
    boost::property_tree::write_json(json, mPTreeRequest);
    std::string result = json.str();

    // Form the request
    std::string requestString =
        "POST " + mURI + " HTTP/1.1\r\n"
        "Host: " + mHost + "\r\n"
        "User-Agent: crappycraft\r\n"
        "Accept: application/json\r\n"
        "Content-Type: application/json; charset=UTF-8\r\n"
        "Content-Length: " + boost::lexical_cast<std::string>(result.length()) + "\r\n"
        "Connection: Close\r\n"
        "\r\n" + result;

    LOG_DEBUG("Sending request");
    async_write(*mpSSLSocket, buffer(requestString), 
        boost::bind(&HTTPSClient::HandleWrite, this, placeholders::error));
}

void HTTPSClient::HandleWrite(const boost::system::error_code &crError)
{
    if (crError)
    {
        LOG_ERROR("Failed to send HTTPS header");
        std::cin.get();
        return;
    }

    LOG_DEBUG("Request sent");

    // Read the response
    async_read_until(*mpSSLSocket, mResponse, "\r\n", 
        boost::bind(&HTTPSClient::HandleReadA, this, placeholders::error));
    //mIOService.run();
}

void HTTPSClient::HandleReadA(const boost::system::error_code &crError)
{
    if (crError)
    {
        LOG_ERROR("Failed to read first header line");
        std::cin.get();
        return;
    }

    // Check if the response is okay.
    std::string httpVersion;
    mResponseStream >> httpVersion;
    LOG_DEBUG("HTTP version: " + httpVersion);
    mResponseStream >> mHTTPSResult.statusCode;
    LOG_DEBUG("Status code: " + boost::lexical_cast<std::string>(mHTTPSResult.statusCode));
    std::string statusMessage;
    std::getline(mResponseStream, statusMessage);
    LOG_DEBUG("Status message:" + statusMessage);

    if (!mResponseStream.good())
    {
        LOG_ERROR("Invalid response");
        std::cin.get();
        return;
    }
    if (httpVersion.substr(0, 5) != "HTTP/")
    {
        LOG_ERROR("Invalid protocol: " + httpVersion);
        std::cin.get();
        return;
    }

    // Read the response headers
    async_read(*mpSSLSocket, mResponse,
        boost::bind(&HTTPSClient::HandleReadB, this, placeholders::error));
    //mIOService.run();
}

void HTTPSClient::HandleReadB(const boost::system::error_code &crError)
{
#ifdef _DEBUG
    LOG_DEBUG("Response header begin");
    std::string header;
    while (std::getline(mResponseStream, header) && (header != "\r" && header != ""))
        std::cout << header << std::endl;
    LOG_DEBUG("Response header end");
#endif

    // Parse the tree
    boost::property_tree::read_json(mResponseStream, mHTTPSResult.pTree);
    LOG_DEBUG("We're done here!");
    mIOService.stop();
}