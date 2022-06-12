#pragma once

#ifdef RV_PLATFORM_WINDOWS

extern Ravi::Application* Ravi::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ravi::CreateApplication();
	app->run();
	delete app;
}

#endif