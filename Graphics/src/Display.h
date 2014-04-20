#ifndef DISPLAY_H
#define DISPLAY_H
#include "Vectors/Vec2.h"
#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>

namespace Graphics
{
    class Display
    {
    public:
        static void Create(Graphics::Vectors::Vec2i size = Graphics::Vectors::Vec2i(1280, 720), 
            bool fullscreen = 0, bool resizable = 1, std::string title = "");

        static void SetWindowSize(Graphics::Vectors::Vec2i size);
        static void SetFullscreen(bool fullscreen);
        static void SetResizable(bool resizable);
        static void SetTitle(std::string title);

        static Graphics::Vectors::Vec2i GetWindowSize();
        static bool GetFullscreen();
        static bool GetResizable();
        static std::string GetTitle();
        static GLFWwindow *GetWindow();

        static void ShowWarning(std::string warning);

        static bool ShouldClose();
        static void PollEvents();

        static void SwapBuffers();
        static void Clear();

    private:
        static Graphics::Vectors::Vec2i mWindowSize;
        static bool mFullscreen;
        static bool mResizable;
        static std::string mTitle;

        static bool mCreated;
        static bool mInitialized;
        static bool mGLEWInitialized;

        static GLFWwindow *mpWindow;
    };
}

#endif
