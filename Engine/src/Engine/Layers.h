#pragma once

#include"Core.h"

#include "Events/Event.h"

namespace Engine {
	
	class ENGINE_API Layers
	{
	public:
		Layers(const std::string& name = "Layers");
		virtual ~Layers();

		virtual void Attach() {}//when a layer is on attach it is basically pushed on the layer stack 
		virtual void Detach() {}//it gets detached when it is removed
		virtual void OnUpdate() {}//it get called by the application when the laye is updated 
		virtual void OnEvent(Event& event) {}

		inline const std::string GetName() const { return debugname; }

	protected:
		std::string debugname;//this variable is for debugging pueposes
	};
}