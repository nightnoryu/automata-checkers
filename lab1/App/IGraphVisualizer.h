#pragma once

#include <memory>
#include <vector>

class IGraphVisualizer
{
public:
	using Edge = std::pair<int, int>;
	using Edges = std::vector<Edge>;

	using Weight = double;
	using Weights = std::vector<Weight>;

	virtual void SetVertexCount(std::size_t count) = 0;
	virtual void SetEdges(Edges const& edges) = 0;
	virtual void SetWeights(Weights const& weights) = 0;
	virtual void DrawGraph(std::string const& filename) = 0;

	virtual ~IGraphVisualizer() = default;
};

using IGraphVisualizerPtr = std::unique_ptr<IGraphVisualizer>;
