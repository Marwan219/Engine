	#pragma once

#include"Engine/Layers.h"
#include"Engine/Events/Event.h"
#include"Engine/Events/KeyEvent.h"
#include"Engine/Events/ApplicationEvent.h"
#include"Engine/Events/MouseEvent.h"


namespace Engine {
	
	class ENGINE_API LayerImGui : public Layers
	{
	public:
		LayerImGui();
		~LayerImGui();

		void Attach();
		void Detach();
		void OnUpdate();
		void OnEvent(Event& e);


		//void Begin();
		//void End();
		//
		//void BlockEvents(bool block) { m_BlockEvents = block; }
		//
		//void SetDarkThemeColors();
	

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseButtonScrooledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

	private:
		//bool m_BlockEvents = true;
		float m_Time = 0.0f;

	};
}