#include "CrappyCraftLauncher.h"
#include "Authenticator.h"
#include "Log.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#if defined(_WIN32) && defined(_DEBUG)
//# define WIN32_LEAN_AND_MEAN
//# include <Windows.h>
#endif

int CrappyCraftLauncher::Main(std::vector<std::string> &arguments)
{
	Authenticator auth;
	auth.Authenticate("vijfhoek", "test123");
    std::cin.get();


	//MessageBox(NULL, "Wait", "Waiting", 0);

	return 0;
}

int main(int argc, char **argv)
{
	std::vector<std::string> arguments(argv, argv + argc);
	return CrappyCraftLauncher().Main(arguments);
}