#include "CGraphVisualizer.h"
#include <fstream>

void CGraphVisualizer::DrawGraph(const std::string& filename)
{
	std::ofstream output(filename);
	if (!output.is_open())
	{
		throw std::runtime_error("failed to open output file for writing");
	}

	IGraphVisualizer::Edges edges = { { 0, 1 }, { 1, 0 } };
	IGraphVisualizer::EdgeLabels names = { "a1", "a2" };
	IGraphVisualizer::Weights weights = { 1, 2 };

	Graph graph(edges.begin(), edges.end(), weights.begin(), edges.size());
	boost::write_graphviz(output, graph, boost::make_label_writer(names.data()));
}
