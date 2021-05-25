#include "EGpch.h"
#include "Application.h"
#include"Log.h"
#include"Events/ApplicationEvent.h"
#include"Core.h"
#include"Input.h"
#include<glad\glad.h>

namespace Engine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	 Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		EG_CORE_ASSERT(!s_Instance, "Aplication already exists");
		s_Instance = this; 

		m_Window = std::unique_ptr<Window>(Window::Create());
		//when windowswions.cpp we generate events we dispatch them too that callback funcion
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	}
	 
	Application::~Application()
	{
		
	}

	void Application::pushLayer(Layers* layer)
	{
		m_LayerStack.pushOverlay(layer);
		layer->Attach();
	}

	void Application::pushOverlay(Layers* layer)
	{
		m_LayerStack.pushOverlay(layer);
		layer->Attach();
	}


	//we use the event disaptcher that was created to dipsatch the appropriate event to the appropriate 
	//function that we hve over here
	void Application::OnEvent(Event& e) 
	{

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));



		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;

		}

	}
	

	void Application::Run()
	{	
		while (m_Running) 
		{
			glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

			for (Layers* layer : m_LayerStack)
				layer->OnUpdate();

		//	auto [x, y] = Input::GetMousePosition();

			//	EG_CORE_TRACE("[0], [1]", x, y);

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

};
