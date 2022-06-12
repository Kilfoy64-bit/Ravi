#pragma once

#include "Core.h"

namespace Ravi {

	class RAVI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in client
	Application* CreateApplication();
}
