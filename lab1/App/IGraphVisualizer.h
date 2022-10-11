#pragma once

#include <memory>
#include <vector>

class IGraphVisualizer
{
public:
	using Edge = std::pair<int, int>;
	using Edges = std::vector<Edge>;

	using EdgeLabel = std::string;
	using EdgeLabels = std::vector<EdgeLabel>;

	using Weight = int;
	using Weights = std::vector<Weight>;

	virtual void DrawGraph(std::string const& filename) = 0;

	virtual ~IGraphVisualizer() = default;
};

using IGraphVisualizerPtr = std::unique_ptr<IGraphVisualizer>;
