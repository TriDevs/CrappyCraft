#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "HTTPSClient.h"

// Prevent anything from including WinSock.h
#ifdef _WIN32
# include <WinSock2.h>
#endif

#include <boost/property_tree/ptree.hpp>
#include <boost/asio/ssl/verify_context.hpp>
#include <string>

struct AuthenticateResult
{
    /// <summary>
    ///     true if authentication went successfully, false otherwise.
    /// </summary>
    bool Success;

    /// <summary>
    ///     A 16 byte authentication token for use with Authenticator::Refresh.
    /// </summary>
    char AccessToken[16];

    /// <summary>
    ///     A 16 byte token unique to every session.
    /// </summary>
    char ClientToken[16];

    /// <summary>
    ///     true if the user has an attached Minecraft account, false
    ///     otherwise.
    /// </summary>
    bool HasMinecraft;

    /// <summary>
    ///     A 16 byte ID for the currently selected player profile.
    /// </summary>
    char ProfileID[16];

    /// <summary>
    ///     The name of the currently selected player profile. This should be
    ///     used as the player name when logging into servers.
    /// </summary>
    std::string ProfileName;

    /// <summary>
    ///     Short description of the error, if one happened. Empty otherwise.
    /// </summary>
    std::string Error;

    /// <summary>
    ///     Message further explaining the error, if one happened. Empty
    ///     otherwise.
    /// </summary>
    std::string ErrorMessage;
};

class Authenticator
{
public:
    AuthenticateResult Authenticate(std::string username, std::string password);


private:
    /// <summary>
    ///     Address to send authentication requests to.
    /// </summary>
    const std::string mcAuthAddress = "authserver.mojang.com";

    /// <summary>
    ///     Name of the agent, in this case Minecraft.
    /// </summary>
    const std::string mcAgentName = "Minecraft";

    /// <summary>
    ///     Agent version, might be increased by the vanilla Minecraft client.
    /// </summary>
    const int mcAgentVersion = 1;

    /// <summary>
    ///     The HTTPSClient class used to authenticate.
    /// </summary>
    HTTPSClient *mpHTTPSClient;
};



#endif
