#ifndef _HTTPSCLIENT_H
#define _HTTPSCLIENT_H

// Prevent anything from including WinSock.h
#include <WinSock2.h>

#include <boost/asio/ssl/verify_context.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/system/error_code.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/thread/thread.hpp>
#include <boost/function.hpp>

class HTTPSRequest
{
public:
    HTTPSRequest(const std::string cHost, const std::string cURI,
        const boost::property_tree::ptree cPTree, boost::asio::io_service &rIOService);

    const std::string mcHost, mcURI;
    const boost::property_tree::ptree mcPTree;

    boost::asio::io_service &mrIOService;
    bool mSuccess, mFinished;
};

class HTTPSClient
{
public:
    HTTPSClient();

    HTTPSRequest SendHTTPSRequest(const boost::property_tree::ptree &crPTree, 
        const std::string cHost, const std::string cURI);

private:
    void HandleResolve(const boost::system::error_code &crError,
        const boost::asio::ip::tcp::resolver::iterator &criEndpoints, HTTPSRequest &rRequest);
    void HandleConnect(const boost::system::error_code &crError, HTTPSRequest &rRequest);

    //std::string mHost, mURI;
    //boost::property_tree::ptree mPTree;
    boost::asio::io_service mIOService;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> *mpSSLSocket;
    //boost::thread mIOThread;
    //boost::function<void()> mCallback;
};

#endif