#pragma once

#include "../../App/IInputOutputAdapter.h"

class CInputOutputAdapter : public IInputOutputAdapter
{
public:
	using Spreadsheet = std::vector<std::vector<std::string>>;

	MealyAutomaton GetMealy(const std::string& filename) override;
	MooreAutomaton GetMoore(const std::string& filename) override;

private:
	static Spreadsheet GetDataFromFile(const std::string& filename);
};
