#include"EGpch.h"
#include"LayerImGui.h"
#include"Platform/OpenGl/ImGuiOpenGLRenderer.h"
#include"GLFW/glfw3.h"
#include"Engine/Application.h"


#include<GLFW\glfw3.h>
#include<glad\glad.h>


namespace Engine {
	LayerImGui::LayerImGui()
		: Layers("ImGuiLayer")
	{
	}

	 LayerImGui::~LayerImGui()
	{

	}

	 void LayerImGui::Attach()
	 {
		 ImGui::CreateContext();
		 ImGui::StyleColorsDark();

		 ImGuiIO& io = ImGui::GetIO();
		 io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		 io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		 //TODO : this is tmeprorarily and sould use ENguine KeyCodes
		 io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		 io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		 io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		 io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		 io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		 io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		 io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		 io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		 io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		 io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		 io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		 io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		 io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		 io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		 io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		 //io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		 io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		 io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		 io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		 io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		 io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		 io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		 ImGui_ImplOpenGL3_Init("#version 410");
	 }

	 void LayerImGui::Detach()
	 {
		
	 }

	 void LayerImGui::OnUpdate()
	 {
		

		 ImGuiIO& io = ImGui::GetIO();
		 Application& app = Application::Get();
		 io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());


		 float time = (float)glfwGetTime();
		 io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
		 m_Time = time;

		 ImGui_ImplOpenGL3_NewFrame();
		 ImGui::NewFrame();

		 static bool show = true;
		 ImGui::ShowDemoWindow(&show);

		 ImGui::Render();
		 ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	 }

	 void LayerImGui::OnEvent(Event& event)
	 {
		 EventDispatcher dispatcher(event);
		 dispatcher.Dispatch<MouseButtonPressedEvent>(EG_BIND_EVENT_FN(LayerImGui::OnMouseButtonPressedEvent));
		 dispatcher.Dispatch<MouseButtonReleasedEvent>(EG_BIND_EVENT_FN(LayerImGui::OnMouseButtonReleasedEvent));
		 dispatcher.Dispatch<MouseMovedEvent>(EG_BIND_EVENT_FN(LayerImGui::OnMouseMovedEvent));
		 dispatcher.Dispatch<MouseScrolledEvent>(EG_BIND_EVENT_FN(LayerImGui::OnMouseButtonScrooledEvent));
		 dispatcher.Dispatch<KeyPressedEvent>(EG_BIND_EVENT_FN(LayerImGui::OnKeyPressedEvent));
		 dispatcher.Dispatch<KeyReleasedEvent>(EG_BIND_EVENT_FN(LayerImGui::OnKeyReleasedEvent));
		 dispatcher.Dispatch<WindowResizeEvent>(EG_BIND_EVENT_FN(LayerImGui::OnWindowResizeEvent));
		 dispatcher.Dispatch<KeyTypedEvent>(EG_BIND_EVENT_FN(LayerImGui::OnKeyTypedEvent));
	 }



	 bool LayerImGui::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	 {
		 ImGuiIO& io = ImGui::GetIO();
		 io.MouseDown[e.GetMouseButton()] = true;
		 return false;
	 }

	
	 bool LayerImGui::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	 {
		 ImGuiIO& io = ImGui::GetIO();
		 io.MouseDown[e.GetMouseButton()] = false;
		 return false;
	 }


	 bool LayerImGui::OnMouseMovedEvent(MouseMovedEvent& e)
	 {
		 ImGuiIO& io = ImGui::GetIO();
		 io.MousePos = ImVec2(e.GetX(), e.GetY());
		 return false;
	 }

	 bool LayerImGui::OnMouseButtonScrooledEvent(MouseScrolledEvent& e)
	 {
		 ImGuiIO& io = ImGui::GetIO();
		 io.MouseWheelH += e.GetXOffset();//H is for horizontal
		 io.MouseWheel += e.GetYOffset();

		 return false;
	 }

	 bool LayerImGui::OnKeyPressedEvent(KeyPressedEvent& e)
	 {
		 ImGuiIO& io = ImGui::GetIO();
		 io.KeysDown[e.GetKeyCode()] = true;

		 io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		 io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		 io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		 io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

		 return false;
	 }

	 bool LayerImGui::OnKeyReleasedEvent(KeyReleasedEvent& e)
	 {
		 ImGuiIO& io = ImGui::GetIO();
		 io.KeysDown[e.GetKeyCode()] = true;


		 return false;
	 }

	 bool LayerImGui::OnKeyTypedEvent(KeyTypedEvent& e)
	 {
		ImGuiIO& io = ImGui::GetIO();
		int Keycode = e.GetKeyCode();
		if (Keycode > 0 && Keycode < 0x1000)
			io.AddInputCharacter((unsigned short)Keycode);

		return false;
	 }

	 bool LayerImGui::OnWindowResizeEvent(WindowResizeEvent& e)
	 {
		 ImGuiIO& io = ImGui::GetIO();
		 io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		 io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		 glViewport(0, 0, e.GetWidth(), e.GetHeight());

		 return false;
	 }

}