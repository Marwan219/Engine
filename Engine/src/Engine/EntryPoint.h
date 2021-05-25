#pragma once

#include"Engine/Log.h"

//a header file for the entry point to be called
#ifdef EG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc , char** argv )
{
	Engine::Log::Init();
	EG_CORE_WARN("inntialized log");
	int a = 5;
	EG_INFO("Hello var={0}",a);

	//printf("My Game Engine\n");
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}

#endif