#include "CVisualizerService.h"

CVisualizerService::CVisualizerService(IInputOutputAdapterPtr&& inputOutputAdapter, IGraphVisualizerPtr&& graphVisualizer)
	: m_inputOutputAdapter(std::move(inputOutputAdapter))
	, m_graphVisualizer(std::move(graphVisualizer))
{
}

void CVisualizerService::DrawMealy(const std::string& inputFilename, const std::string& outputFilename)
{
	auto const automaton = m_inputOutputAdapter->GetMealy(inputFilename);
	m_graphVisualizer->DrawGraph(outputFilename);
}

void CVisualizerService::DrawMoore(const std::string& inputFilename, const std::string& outputFilename)
{
	auto const automaton = m_inputOutputAdapter->GetMoore(inputFilename);
	// TODO: implement drawing using m_graphVisualizer
}
