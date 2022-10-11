#include "CVisualizerService.h"

CVisualizerService::CVisualizerService(IInputOutputAdapterPtr&& inputOutputAdapter, IGraphVisualizerPtr&& graphVisualizer)
	: m_inputOutputAdapter(std::move(inputOutputAdapter))
	, m_graphVisualizer(std::move(graphVisualizer))
{
}

void CVisualizerService::DrawMealy(const std::string& inputFilename, const std::string& outputFilename)
{
	auto const automaton = m_inputOutputAdapter->GetMealy(inputFilename);

	IGraphVisualizer::Vertices vertices = automaton.states;

	std::unordered_map<std::string, int> stateToIndexMap;
	for (std::size_t i = 0; i < automaton.states.size(); ++i)
	{
		stateToIndexMap[automaton.states[i]] = static_cast<int>(i);
	}

	IGraphVisualizer::Edges edges;
	for (auto&& [stateAndSymbol, stateAndSignal] : automaton.moves)
	{
		edges.push_back({ .from = stateToIndexMap[stateAndSymbol.state],
			.to = stateToIndexMap[stateAndSignal.state],
			.label = stateAndSymbol.symbol + "/" + stateAndSignal.signal });
	}

	m_graphVisualizer->SetVertices(std::move(vertices));
	m_graphVisualizer->SetEdges(std::move(edges));

	m_graphVisualizer->DrawGraph(outputFilename);
}

void CVisualizerService::DrawMoore(const std::string& inputFilename, const std::string& outputFilename)
{
	auto const automaton = m_inputOutputAdapter->GetMoore(inputFilename);
	// TODO: implement drawing using m_graphVisualizer
}
