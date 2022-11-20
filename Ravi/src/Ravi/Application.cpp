#include "rvpch.h"
#include "Application.h"

#include "Ravi/Events/ApplicationEvent.h"
#include "Ravi/Log.h"

namespace Ravi {

	Ravi::Application::Application()
	{
	}

	Ravi::Application::~Application()
	{
	}

	void Application::run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			RV_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			RV_TRACE(e);
		}

		while (true);
	}

}
