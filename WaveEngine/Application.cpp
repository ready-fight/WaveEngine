#include "Application.h"

#include <GL/glew.h>

namespace Wave 
{
	Application::Application() : m_window(1280, 720, "Wave Engine")
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (!m_window.ShouldClose())
		{
			m_window.ProcessEvents();

			m_renderer.Render(m_window.GetAspectRatio());

			m_window.SwapBuffers();
		}
	}
}
