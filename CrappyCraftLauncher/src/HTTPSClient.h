#ifndef _HTTPSCLIENT_H
#define _HTTPSCLIENT_H

// Prevent anything from including WinSock.h
#include <WinSock2.h>

#include <boost/asio/ssl/verify_context.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/system/error_code.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/thread/thread.hpp>
#include <boost/function.hpp>

struct HTTPSResult
{
    int statusCode;
    boost::property_tree::ptree pTree;
};

class HTTPSClient
{
public:
    HTTPSClient();

    HTTPSResult SendHTTPSRequest(const boost::property_tree::ptree &crPTree,
        const std::string cHost, const std::string cURI);

private:
    void HandleResolve(const boost::system::error_code &crError,
        const boost::asio::ip::tcp::resolver::iterator &criEndpoints);
    void HandleConnect(const boost::system::error_code &crError);
    void HandleHandshake(const boost::system::error_code &crError);
    void HandleWrite(const boost::system::error_code &crError);
    void HandleReadA(const boost::system::error_code &crError);
    void HandleReadB(const boost::system::error_code &crError);

    boost::asio::io_service mIOService;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> *mpSSLSocket;

    std::string mHost, mURI;
    boost::property_tree::ptree mPTreeRequest;
    HTTPSResult mHTTPSResult;

    boost::asio::streambuf mResponse;
    std::istream mResponseStream;
    bool mSuccess, mFinished;
};

#endif