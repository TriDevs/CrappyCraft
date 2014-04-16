#include "CrappyCraftLauncher.h"
#include "Authenticator.h"
#include "Log.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/lexical_cast.hpp>
#ifdef _WIN32
# include <windows.h>
# include <Shlobj.h>
#endif

int CrappyCraftLauncher::Main(std::vector<std::string> &arguments)
{
    if (arguments.size() != 3)
    {
        std::cout << "Syntax: " << arguments[0] << " <username> <password>" << std::endl;
        return 1;
    }

    Authenticator auth;
    AuthenticateResult r = auth.Authenticate(arguments[1], arguments[2]);

    if (!r.Success)
    {
        std::cerr << "Failed to log in: " << r.ErrorMessage << std::endl;
        return 1;
    }

    if (!r.HasMinecraft)
    {
        std::cerr << "You need a Minecraft license to start CrappyCraft." << std::endl;
        return 1;
    }

    LaunchCrappyCraft();

    return 0;
}


void CrappyCraftLauncher::LaunchCrappyCraft()
{
#ifdef _WIN32
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    PROCESS_INFORMATION pi;
    ZeroMemory(&pi, sizeof(pi));

    // Get the AppData folder
    char appdata[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, appdata);

    std::string path = (std::string)appdata + "\\CrappyCraft\\bin\\crappycraft.exe";

    LOG_DEBUG(path);

    CreateProcessA(path.c_str(), NULL, NULL, NULL, false, 0, NULL, NULL, &si, &pi);

    LOG_DEBUG(boost::lexical_cast<std::string>(GetLastError()));
    //CloseHandle(pi.hProcess);
    //CloseHandle(pi.hThread);
#elif defined(__unix__)
    
#endif
}

int main(int argc, char **argv)
{
    std::vector<std::string> arguments(argv, argv + argc);
    return CrappyCraftLauncher().Main(arguments);
}