#pragma once

#include "../../App/IGraphVisualizer.h"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

class CGraphVisualizer : public IGraphVisualizer
{
public:
	void DrawGraph(std::string const& filename) override;

private:
	using Graph = boost::adjacency_list<
		boost::vecS,
		boost::vecS,
		boost::directedS,
		boost::property<boost::vertex_color_t, boost::default_color_type>,
		boost::property<boost::edge_weight_t, IGraphVisualizer::Weight>>;
};
