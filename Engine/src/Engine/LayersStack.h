#pragma once

#include"Engine/Core.h"
#include"Layers.h"

#include<vector>

namespace Engine {

	class ENGINE_API LayersStack
	{
	public:
		LayersStack();
		~LayersStack();

		void pushLayers(Layers* layer);
		void pushOverlay(Layers* overlay);
		void popLayers(Layers* layer);
		void popOverlay(Layers* layer);

		std::vector<Layers*>::iterator begin() { return m_Layers.begin();}
		std::vector<Layers*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layers*> m_Layers;
		std::vector<Layers*>::iterator m_LayerInsert;

	};
}