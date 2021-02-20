#include "EGpch.h"

#include "Application.h"
#include"Events\ApplicationEvent.h"
#include"Log.h"

namespace Engine {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	 
	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (Running);
		{
			m_Window->OnUpdate();
		}
	}
};
