#include "Authenticator.h"
#include "HTTPSClient.h"
#include "Log.h"
#define WIN32_LEAN_AND_MEAN 
#include <boost/property_tree/json_parser.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
/*
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/context.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
*/
#include <sstream>

void Authenticator::Authenticate(std::string username, std::string password) const
{
    using boost::property_tree::ptree;

    ptree pt;
    
    // Fill the property tree with the necessary information
    pt.put("agent.name", mcAgentName);
    pt.put("agent.version", mcAgentVersion);
    pt.put("username", username);
    pt.put("password", password);

#ifdef _DEBUG
    // When debugging, output the ptree
    LOG_DEBUG("Authenticate JSON begin");
    write_json(std::cout, pt);
    LOG_DEBUG("Authenticate JSON end");
#endif

    HTTPSClient https;
    https.SendHTTPSRequest(pt, mcAuthAddress, "/authenticate");    
}

