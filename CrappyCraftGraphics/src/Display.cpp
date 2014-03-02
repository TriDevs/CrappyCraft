#include "Display.h"
#include <GLFW/glfw3.h>

void Graphics::Display::Create(Vec2i size, bool fullscreen, bool resizable, std::string title)
{
    mWindowSize = size;
    mFullscreen = fullscreen;
    mResizable = resizable;
    mTitle = title;

    if (!mInitialized)
        glfwInit();

    glfwWindowHint(GLFW_RESIZABLE, mResizable);

    mpWindow = glfwCreateWindow(mWindowSize.X, mWindowSize.Y, mTitle.c_str(), 
        mFullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
}

void Graphics::Display::SetWindowSize(Vec2i size)
{
    mWindowSize = size;

    if (mCreated)
    {
        glfwSetWindowSize(mpWindow, size.X, size.Y);
    }
}

void Graphics::Display::SetFullscreen(bool fullscreen)
{
    if (mFullscreen != fullscreen)
    {
        mFullscreen = fullscreen;

        if (mCreated)
        {
            glfwDestroyWindow(mpWindow);
            Create(mWindowSize, mFullscreen, mResizable, mTitle);
        }
    }
}

void Graphics::Display::SetResizable(bool resizable)
{
    if (mResizable != resizable)
    {
        mResizable = resizable;

        if (mCreated)
        {
            glfwDestroyWindow(mpWindow);
            Create(mWindowSize, mFullscreen, mResizable, mTitle);
        }
    }
}

void Graphics::Display::SetTitle(std::string title)
{
    mTitle = title;

    if (mCreated)
    {
        glfwSetWindowTitle(mpWindow, mTitle.c_str());
    }
}


Vec2i Graphics::Display::GetWindowSize()
{
    return mWindowSize;
}

bool Graphics::Display::GetFullscreen()
{
    return mFullscreen;
}

bool Graphics::Display::GetResizable()
{
    return mResizable;
}

std::string Graphics::Display::GetTitle()
{
    return mTitle;
}

GLFWwindow *Graphics::Display::GetWindow()
{
    return mpWindow;
}


bool Graphics::Display::ShouldClose()
{
    return glfwWindowShouldClose(mpWindow) & 1; // "& 1" to stop MSVC from complaining
}

void Graphics::Display::SwapBuffers()
{
    glfwSwapBuffers(mpWindow);
}

Vec2i Graphics::Display::mWindowSize;
bool Graphics::Display::mFullscreen;
bool Graphics::Display::mResizable;
std::string Graphics::Display::mTitle;

bool Graphics::Display::mCreated;
bool Graphics::Display::mInitialized;
GLFWwindow *Graphics::Display::mpWindow;
