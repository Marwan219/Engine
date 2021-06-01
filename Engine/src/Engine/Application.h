#pragma once
#include"Core.h"
#include"Events\Event.h"
#include"Events\ApplicationEvent.h"
#include"Window.h"
#include"LayersStack.h"
#include"Engine\ImGui\LayerImGui.h"
#include "Engine\Renderer\Shader.h"
#include "Engine\Renderer\Buffer.h"
#include "Engine\Renderer\VertexArray.h"
#include"Renderer\OrthorgraphicCamera.h"

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
		LayerImGui* m_LayerImGui;
		bool m_Running = true;
		LayersStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;


		static  Application* s_Instance;
	};


	//to be deifned in client
	Application* CreateApplication();

}
 

