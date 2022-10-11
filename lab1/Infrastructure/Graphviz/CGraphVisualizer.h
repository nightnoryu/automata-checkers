#pragma once

#include "../../App/IGraphVisualizer.h"

class CGraphVisualizer : public IGraphVisualizer
{
public:
	void SetVertices(IGraphVisualizer::Vertices&& vertices);
	void SetEdges(IGraphVisualizer::Edges&& edges);
	void DrawGraph(std::string const& filename) override;

private:
	IGraphVisualizer::Vertices m_vertices;
	IGraphVisualizer::Edges m_edges;
};
