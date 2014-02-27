#include "HTTPSClient.h"
#include "Log.h"
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/thread.hpp>
#include <boost/function.hpp>
#include <string>

using namespace boost::asio;

HTTPSClient::HTTPSClient()
{
    ssl::context context(ssl::context::sslv23);
    context.set_verify_mode(ssl::verify_peer);
    context.set_default_verify_paths();
    context.load_verify_file("mojang.pem");
    mSSLSocket = new ssl::stream<ip::tcp::socket>(mIOService, context);
}

HTTPSRequest HTTPSClient::SendHTTPSRequest(const boost::property_tree::ptree &crPTree,
    const std::string cHost, const std::string cURI)
{
    HTTPSRequest request(cHost, cURI, crPTree, mIOService);

    LOG_DEBUG("Resolving " + cHost);

    // Resolve the Minecraft authentication server name
    ip::tcp::resolver::iterator tcpEndpointIterator;
    try
    {
        // Resolve the host
        ip::tcp::resolver tcpResolver(mIOService);
        ip::tcp::resolver::query tcpResolverQuery(cHost, "https");
        tcpResolver.async_resolve(tcpResolverQuery, boost::bind(&HTTPSClient::HandleResolve, this, 
            placeholders::error, placeholders::iterator, request));
        
        boost::thread ioThread(boost::bind(&io_service::run, &mIOService));
        
        while (true);
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

    return request;
}

void HTTPSClient::HandleResolve(const boost::system::error_code &crError,
    const ip::tcp::resolver::iterator &criEndpoints, HTTPSRequest &rRequest)
{
    if (crError)
    {
        LOG_ERROR("Failed to resolve host " + rRequest.mcHost);
        std::cin.get();
        return;
    }

    try
    {
        // Connect to the first endpoint we can connect with
        async_connect(mSSLSocket->lowest_layer(), criEndpoints,
            boost::bind(&HTTPSClient::HandleConnect, this, placeholders::error, rRequest));
    }
    catch (boost::system::system_error ex)
    {
        LOG_ERROR(ex.what());
        std::cin.get();
        return;
    }
    catch (std::exception ex)
    {
        LOG_ERROR(ex.what());
        std::cin.get();
        return;
    }
}

void HTTPSClient::HandleConnect(const boost::system::error_code &crError, HTTPSRequest &rRequest)
{
    if (crError)
    {
        LOG_ERROR("Failed to connect to host");
        std::cin.get();
        return;
    }

    try
    {
        char port[6];
        _itoa_s(mSSLSocket->lowest_layer().remote_endpoint().port(), port, 10);
        LOG_DEBUG("Connected to " + mSSLSocket->lowest_layer().remote_endpoint().address().to_string()
            + std::string(":") + port);

        mSSLSocket->lowest_layer().set_option(ip::tcp::no_delay(true));
        mSSLSocket->set_verify_callback(ssl::rfc2818_verification(rRequest.mcHost));

        // Perform a handshake
        LOG_DEBUG("Performing SSL handshake");
        mSSLSocket->handshake(ssl::stream_base::client);
        LOG_DEBUG("SSL handshake successful!");

        // Write the json into a stringstream
        std::ostringstream json;
        boost::property_tree::write_json(json, rRequest.mcPTree);
        std::string result;
        result = json.str();

        // Form the request
        streambuf request;
        std::ostream requestStream(&request);
        requestStream << "POST " << rRequest.mcURI << " HTTP/1.1\r\n";
        requestStream << "Host: " << rRequest.mcHost << "\r\n";
        requestStream << "Accept: *\r\n";
        requestStream << "Content-Type: application/json\r\n";
        requestStream << "Content-Length: " << result.length() << "\r\n\r\n";
        requestStream << result << "\r\n\r\n";

#ifdef _DEBUG
        LOG_DEBUG("Request stream begin");
        std::cout << requestStream.rdbuf();
        LOG_DEBUG("Request stream end");
#endif

        LOG_DEBUG("Sending request");

        // Send the request
        write(*mSSLSocket, request);

        LOG_DEBUG("Request sent");

        // Read the response
        streambuf response;
        read_until(*mSSLSocket, response, "\r\n");
        std::istream responseStream(&response);

#ifdef _DEBUG
        LOG_DEBUG("Response begin");
        std::cout << responseStream.rdbuf();
        LOG_DEBUG("Response end");
#endif

        // Check if the response is okay.
        std::string httpVersion;
        responseStream >> httpVersion;
        unsigned int statusCode;
        responseStream >> statusCode;
        std::string statusMessage;
        std::getline(responseStream, statusMessage);

        if (!responseStream)
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
        read_until(*mSSLSocket, response, "\r\n\r\n");

#ifdef _DEBUG
        std::cout << "[DEBUG][Authenticator] Response header begin" << std::endl;
        std::string header;
        while (std::getline(responseStream, header) && (header != "\r" || header != ""))
            std::cout << header << std::endl;
        std::cout << "[DEBUG][Authenticator] Response header end" << std::endl;
#endif

        // TODO: Make this thread-safe
        rRequest.mFinished = true;
    }
    catch (boost::system::system_error ex)
    {
        LOG_ERROR(ex.what());
        std::cin.get();
        return;
    }
    catch (std::exception ex)
    {
        LOG_ERROR(ex.what());
        std::cin.get();
        return;
    }
}

bool HTTPSClient::VerifySSLCertificate(const bool preverified,
    boost::asio::ssl::verify_context &verifyContext) const
{
    char pSubjectName[256];
    X509 *pCertificate = X509_STORE_CTX_get_current_cert(verifyContext.native_handle());
    X509_NAME_oneline(X509_get_subject_name(pCertificate), pSubjectName, 256);
    std::cout << "[DEBUG][HTTPSClient] Verifying certificate " << pSubjectName << std::endl;
    return preverified;
}


HTTPSRequest::HTTPSRequest(const std::string cHost, const std::string cURI,
    const boost::property_tree::ptree cPTree, io_service &rIOService) 
    : mcHost(cHost), mcURI(cURI), mcPTree(cPTree), mrIOService(rIOService)
{
}