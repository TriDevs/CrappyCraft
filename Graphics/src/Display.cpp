#if defined(_WIN32)
# define WIN32_LEAN_AND_MEAN
# include <Windows.h>
#endif
#include "Display.h"
#include <stdexcept>

void Graphics::Display::Create(Graphics::Vectors::Vec2i size, bool fullscreen, bool resizable, std::string title)
{
    mWindowSize = size;
    mFullscreen = fullscreen;
    mResizable = resizable;
    mTitle = title;

    if (!mInitialized)
        mInitialized = glfwInit() & 1;
    if (!mInitialized) throw std::runtime_error("Error initializing GLFW.");

    glfwWindowHint(GLFW_RESIZABLE, mResizable);

    mpWindow = glfwCreateWindow(mWindowSize.X, mWindowSize.Y, mTitle.c_str(), 
        mFullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    if (!mpWindow)
    {
        glfwTerminate();
        throw std::runtime_error("Error creating GLFW window.");
    }

    glfwMakeContextCurrent(mpWindow);

    GLenum err;
    if (!mGLEWInitialized)
        mGLEWInitialized = GLEW_OK == (err = glewInit());
    if (!mGLEWInitialized)
    {
        glfwTerminate();
        throw std::runtime_error("Error initializing GLEW: " + std::string((const char *)glewGetErrorString(err)));
    }
}

void Graphics::Display::SetWindowSize(Graphics::Vectors::Vec2i size)
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


Graphics::Vectors::Vec2i Graphics::Display::GetWindowSize()
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

void Graphics::Display::PollEvents()
{
    glfwPollEvents();
}

void Graphics::Display::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Graphics::Display::ShowWarning(std::string warning)
{
#if defined(_WIN32)
    MessageBoxA(NULL, warning.c_str(), "Warning", MB_ICONWARNING);
#endif
}

Graphics::Vectors::Vec2i Graphics::Display::mWindowSize;
bool Graphics::Display::mFullscreen;
bool Graphics::Display::mResizable;
std::string Graphics::Display::mTitle;

bool Graphics::Display::mCreated;
bool Graphics::Display::mInitialized;
bool Graphics::Display::mGLEWInitialized;
GLFWwindow *Graphics::Display::mpWindow;
