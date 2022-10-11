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
		IGraphVisualizer::Edge edge = {
			.from = stateToIndexMap[stateAndSymbol.state],
			.to = stateToIndexMap[stateAndSignal.state],
			.label = stateAndSymbol.symbol + "/" + stateAndSignal.signal
		};
		edges.push_back(std::move(edge));
	}

	m_graphVisualizer->SetVertices(std::move(vertices));
	m_graphVisualizer->SetEdges(std::move(edges));

	m_graphVisualizer->DrawGraph(outputFilename);
}

void CVisualizerService::DrawMoore(const std::string& inputFilename, const std::string& outputFilename)
{
	auto const automaton = m_inputOutputAdapter->GetMoore(inputFilename);

	IGraphVisualizer::Vertices vertices;
	for (auto&& state : automaton.states)
	{
		vertices.push_back(state + "/" + automaton.stateSignals.at(state));
	}

	std::unordered_map<std::string, int> stateToIndexMap;
	for (std::size_t i = 0; i < automaton.states.size(); ++i)
	{
		stateToIndexMap[automaton.states[i]] = static_cast<int>(i);
	}

	IGraphVisualizer::Edges edges;
	for (auto&& [stateAndSymbol, state] : automaton.moves)
	{
		IGraphVisualizer::Edge edge = {
			.from = stateToIndexMap[stateAndSymbol.state],
			.to = stateToIndexMap[state],
			.label = stateAndSymbol.symbol,
		};
		edges.push_back(std::move(edge));
	}

	m_graphVisualizer->SetVertices(std::move(vertices));
	m_graphVisualizer->SetEdges(std::move(edges));

	m_graphVisualizer->DrawGraph(outputFilename);
}
