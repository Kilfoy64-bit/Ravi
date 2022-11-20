#include "rvpch.h"
#include "Application.h"

#include "Ravi/Events/ApplicationEvent.h"
#include "Ravi/Log.h"

#include <GLFW/glfw3.h>

namespace Ravi {

	Ravi::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Ravi::Application::~Application()
	{
	}

	void Application::run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}
