#pragma once
#include"Core.h"
#include"Events\Event.h"
#include"Events\ApplicationEvent.h"
#include"Window.h"
#include"LayersStack.h"

namespace Engine {
	class ENGINE_API Application
	{
	public:
		 Application();
		 ~Application();

		void Run();

		void OnEvent(Event& e);

		void pushLayer(Layers* layer);
		void pushOverlay(Layers* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);


		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayersStack m_LayerStack;

		static  Application* s_Instance;
	};


	//to be deifned in client
	Application* CreateApplication();

}
 

