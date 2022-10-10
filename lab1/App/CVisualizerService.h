#pragma once

#include "IGraphVisualizer.h"
#include "IInputOutputAdapter.hpp"

class CVisualizerService
{
public:
	CVisualizerService(IInputOutputAdapterPtr&& inputOutputAdapter, IGraphVisualizerPtr&& graphVisualizer);

	void DrawMealy(std::string const& inputFilename, std::string const& outputFilename);
	void DrawMoore(std::string const& inputFilename, std::string const& outputFilename);

private:
	IInputOutputAdapterPtr m_inputOutputAdapter;
	IGraphVisualizerPtr m_graphVisualizer;
};
