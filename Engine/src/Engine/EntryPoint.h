#pragma once

#include"Engine/Log.h"

//a header file for the entry point to be called
#ifdef EG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc , char** argv )
{
	Engine::Log::Init();
	Engine::Log::GetCorelogger()->warn("inntialized log");
	Engine::Log::GetClientlogger()->info("hi");

	//printf("My Game Engine\n");
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}

#endif