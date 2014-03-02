#ifndef DISPLAY_H
#define DISPLAY_H
#include "Vectors/Vec2.h"
#include <glfw/glfw3.h>
#include <string>

namespace Graphics
{
	class Display
	{
	public:
		static void Create(Vec2i size = { 1280, 720 }, bool fullscreen = 0, bool resizable = 1, 
			std::string title = "");

		static void SetWindowSize(Vec2i size);
		static void SetFullscreen(bool fullscreen);
		static void SetResizable(bool resizable);
		static void SetTitle(std::string title);

		static Vec2i GetWindowSize();
		static bool GetFullscreen();
		static bool GetResizable();
		static std::string GetTitle();
		static GLFWwindow *GetWindow();

		static bool ShouldClose();
		static void SwapBuffers();

	private:
		static Vec2i mWindowSize;
		static bool mFullscreen;
		static bool mResizable;
		static std::string mTitle;

		static bool mCreated;
		static bool mInitialized;
		static GLFWwindow *mpWindow;
	};
}

#endif