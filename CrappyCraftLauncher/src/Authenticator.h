#ifndef _AUTHENTICATOR_H
#define _AUTHENTICATOR_H

// Prevent anything from including WinSock.h
#include <WinSock2.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/asio/ssl/verify_context.hpp>
#include <string>

class Authenticator
{
public:
	void Authenticate(std::string username, std::string password) const;

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
};

#endif