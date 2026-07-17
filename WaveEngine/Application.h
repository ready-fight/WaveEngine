#pragma once

#include "Window.h"
#include "Renderer.h"

namespace Wave 
{
	class Application
	{
	public:
		Application();
		~Application();

		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		void Run();

	private:
		Window m_window;
		Renderer m_renderer;
	};
}

