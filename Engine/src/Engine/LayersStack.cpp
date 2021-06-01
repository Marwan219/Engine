#include"EGpch.h"

#include"LayersStack.h"

namespace Engine {

	LayersStack::LayersStack()
	{
		
	}

	LayersStack::~LayersStack()
	{
		for (Layers* layer : m_Layers)
			delete layer;
	}

	void LayersStack::pushLayers(Layers* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayersStack::pushOverlay(Layers* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayersStack::popLayers(Layers* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())		
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}


	void LayersStack::popOverlay(Layers* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}

}