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

		
	

		virtual void Attach() override;
		virtual void Detach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		//bool m_BlockEvents = true;
		float m_Time = 0.0f;

	};
}