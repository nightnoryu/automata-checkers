#pragma once

#include "../../App/IInputOutputAdapter.hpp"

class CInputOutputAdapter : public IInputOutputAdapter
{
public:
	MealyAutomaton GetMealy(const std::string& filename) override;
	MooreAutomaton GetMoore(const std::string& filename) override;
};
