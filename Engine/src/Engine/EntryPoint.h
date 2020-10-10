#pragma once
//a header file for the entry point to be called
#ifdef EG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc , char** argv )
{
	printf("My Game Engine\n")
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}

#endif