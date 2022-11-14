#pragma once

#ifdef RV_PLATFORM_WINDOWS

extern Ravi::Application* Ravi::CreateApplication();

int main(int argc, char** argv)
{
	Ravi::Log::init();
	RV_CORE_WARN("Initialized Log!");
	int a = 5;
	RV_INFO("Hello Var={0}", a);

	auto app = Ravi::CreateApplication();
	app->run();
	delete app;
}

#endif