
#include <Engine.h>

class Sandbox : public Engine::Application
{
public:
	Sandbox(){}
	~Sandbox(){}
};

Engine::Application* Engine::CreateApplication()//this is where is the enrty point is called
{
	return new Sandbox();
}