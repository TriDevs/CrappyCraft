#include "CrappyCraft.h"
#include <Display.h>
#include <Controls/Button.h>
#include <iostream>
#include <stdexcept>

int CrappyCraft::Main(std::vector<std::string> &arguments)
{
    try
    {
        Graphics::Display::Create(Vec2i(1280, 720), false, true, "CrappyCraft");
    }
    catch (std::exception e)
    {
        Graphics::Display::ShowWarning(e.what());
        exit(EXIT_FAILURE);
    }

    Graphics::Controls::Button button(1, Vec2d(-0.5, -0.075), Vec2d(1.0, 0.15), "Button!");
    while (!Graphics::Display::ShouldClose())
    {
        Graphics::Display::Clear();

        button.Render();

        Graphics::Display::SwapBuffers();
        Graphics::Display::PollEvents();
    }

    return 0;
}

int main(int argc, char **argv)
{
    std::vector<std::string> arguments(argv, argv + argc);
    return CrappyCraft().Main(arguments);
}