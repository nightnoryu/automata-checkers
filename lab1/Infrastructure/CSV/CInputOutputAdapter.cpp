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
		},
	};
}

MooreAutomaton CInputOutputAdapter::GetMoore(const std::string& filename)
{
	// TODO: implement parsing from CSV
	return {
		.states = { "S0", "S1", "S2", "S3", "S4" },
		.inputSymbols = { "z1", "z2" },
		.stateSignals = {
			{"S0", "w1"},
			{"S1", "w1"},
			{"S2", "w2"},
			{"S3", "w2"},
			{"S4", "w1"},
		},
		.moves = {
			{ { "S0", "z1" }, "S2" },
			{ { "S0", "z2" }, "S4" },
			{ { "S1", "z1" }, "S0" },
			{ { "S1", "z2" }, "S1" },
			{ { "S2", "z1" }, "S0" },
			{ { "S2", "z2" }, "S1" },
			{ { "S3", "z1" }, "S2" },
			{ { "S3", "z2" }, "S4" },
			{ { "S4", "z1" }, "S1" },
			{ { "S4", "z2" }, "S3" },
		},
	};
}
