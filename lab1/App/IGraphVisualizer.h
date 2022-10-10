#pragma once

#include <memory>

class IGraphVisualizer
{
public:
	// TODO: add interface according to boost capabilities

	virtual ~IGraphVisualizer() = default;
};

using IGraphVisualizerPtr = std::unique_ptr<IGraphVisualizer>;
