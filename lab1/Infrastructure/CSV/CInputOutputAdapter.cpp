#include "CInputOutputAdapter.h"

MealyAutomaton CInputOutputAdapter::GetMealy(const std::string& filename)
{
	// TODO: implement parsing from CSV
	return {
		.states = { "a1", "a2", "a3" },
		.inputSymbols = { "z1", "z2" },
		.moves = {
			{ { "a1", "z1" }, { "a3", "w1" } },
			{ { "a1", "z2" }, { "a1", "w1" } },
			{ { "a2", "z1" }, { "a1", "w1" } },
			{ { "a2", "z2" }, { "a3", "w2" } },
			{ { "a3", "z1" }, { "a1", "w2" } },
			{ { "a3", "z2" }, { "a2", "w1" } },
		}
	};
}

MooreAutomaton CInputOutputAdapter::GetMoore(const std::string& filename)
{
	// TODO: implement parsing from CSV
	return {};
}
