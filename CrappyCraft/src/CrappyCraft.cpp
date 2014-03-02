#include "CrappyCraft.h"
#include <Display.h>

int CrappyCraft::Main(std::vector<std::string> &arguments)
{
    Graphics::Display::Create(Vec2i(1280, 720), false, true, "CrappyCraft");
    while (1);

    return 0;
}

int main(int argc, char **argv)
{
    std::vector<std::string> arguments(argv, argv + argc);
    return CrappyCraft().Main(arguments);
}