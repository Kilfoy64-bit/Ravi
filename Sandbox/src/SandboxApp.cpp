#include <Ravi.h>

class Sandbox : public Ravi::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};


Ravi::Application* Ravi::CreateApplication()
{
	return new Sandbox();
}