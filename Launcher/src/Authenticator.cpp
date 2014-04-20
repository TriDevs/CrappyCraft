#include "Authenticator.h"
#include "HTTPSClient.h"
#include "Log.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/lexical_cast.hpp>
#include <sstream>

AuthenticateResult Authenticator::Authenticate(std::string username, std::string password)
{
    using namespace boost;

    property_tree::ptree pTree;
    
    // Fill the property tree with the necessary information
    pTree.put("agent.name", mcAgentName);
    pTree.put("agent.version", mcAgentVersion);
    pTree.put("username", username);
    pTree.put("password", password);

#ifdef _DEBUG
    // When debugging, output the ptree
    LOG_DEBUG("Authenticate JSON begin");
    property_tree::write_json(std::cout, pTree);
    LOG_DEBUG("Authenticate JSON end");
#endif

    mpHTTPSClient = new HTTPSClient;
    HTTPSResult httpsResult = mpHTTPSClient->SendHTTPSRequest(pTree, mcAuthAddress, "/authenticate");

#ifdef _DEBUG
    // When debugging, output the result
    LOG_DEBUG("Result status code: " + lexical_cast<std::string>(httpsResult.statusCode));
    LOG_DEBUG("Result JSON begin");
    property_tree::write_json(std::cout, httpsResult.pTree);
    LOG_DEBUG("Result JSON end");
#endif

    try
    {

        AuthenticateResult result;
        if (httpsResult.statusCode == 200)
        {
            result.Success = true;

            // Lambda goodness!
            auto lHexToCharAry = [](char *src, char *dst)
            {
                unsigned int u;
                while (*src != 0 && scanf(src, "%2x", &u) == 1)
                {
                    *dst++ = u;
                    src += 2;
                }
            };

            std::string str = httpsResult.pTree.get<std::string>("accessToken");
            lHexToCharAry((char *)str.c_str(), result.AccessToken);

            str = httpsResult.pTree.get<std::string>("clientToken");
            lHexToCharAry((char *)str.c_str(), result.ClientToken);

            if (httpsResult.pTree.count("selectedProfile"))
            {
                result.HasMinecraft = true;

                str = httpsResult.pTree.get<std::string>("selectedProfile.id");
                lHexToCharAry((char *)str.c_str(), result.ProfileID);

                result.ProfileName = httpsResult.pTree.get<std::string>("selectedProfile.name");
            }
            else
            {
                result.HasMinecraft = false;
            }
        }
        else
        {
            result.Success = false;

            result.Error = httpsResult.pTree.get<std::string>("error", "UnknownErrorException");
            result.ErrorMessage = httpsResult.pTree.get<std::string>("errorMessage",
                "No description available.");
        }
        return result;

    }
    catch (boost::system::system_error e)
    {
        LOG_ERROR(e.what());
        std::cin.get();

        AuthenticateResult ar;
        ar.Success = false;
        return ar;
    }
}

