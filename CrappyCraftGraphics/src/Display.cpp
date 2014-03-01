#include "Display.h"
#include <GLFW/glfw3.h>

void Graphics::Display::Create(Vec2i size, bool fullscreen, bool resizable, std::string title)
{
	mWindowSize = size;
	mFullscreen = fullscreen;
	mResizable = resizable;
	mTitle = title;

	mpWindow = glfwCreateWindow(size.x, size.y, title.c_str(),
		mFullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
}

void Graphics::Display::SetWindowSize(Vec2i size)
{
	mWindowSize = size;
	glfwSetWindowSize(mpWindow, size.x, size.y);
}

void Graphics::Display::SetFullscreen(bool fullscreen)
{
	mFullscreen = fullscreen;
}

void Graphics::Display::SetResizable(bool resizable)
{
	mResizable = resizable;
}

void Graphics::Display::SetTitle(std::string title)
{
	mTitle = title;
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