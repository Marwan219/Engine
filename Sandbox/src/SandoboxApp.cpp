#include <Engine.h>
#include "ImGui\imgui.h"
#include"imgui\imgui.h"

class TestLayer : public Engine::Layers
{
public:
	TestLayer()
		: Layers("Test"){}


	void OnUpdate() override
	{

		if (Engine::Input::IsKeyPressed(EG_KEY_TAB))
			EG_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}


	void OnEvent(Engine::Event& event) override
	{
		if (event.GetEventType() == Engine::EventType::KeyPressed)
		{
			Engine::KeyPressedEvent& e = (Engine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == EG_KEY_TAB)
				EG_TRACE("Tab key is pressed (event)!");
			EG_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public Engine::Application
{
public:

	Sandbox()
	{
		pushLayer(new TestLayer());
		//pushOverlay(new Engine::LayerImGui());
	}

	~Sandbox()
	{

	}
};



Engine::Application* Engine::CreateApplication()//this is where is the enrty point is called
{
	return new Sandbox();
}