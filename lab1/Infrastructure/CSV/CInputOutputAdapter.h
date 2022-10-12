#pragma once

#include "../../App/IInputOutputAdapter.h"

class CInputOutputAdapter : public IInputOutputAdapter
{
public:
	MealyAutomaton GetMealy(const std::string& filename) override;
	MooreAutomaton GetMoore(const std::string& filename) override;

private:
	using Spreadsheet = std::vector<std::vector<std::string>>;

	static auto const CSV_SEPARATOR = ';';
	static auto const STATE_AND_SIGNAL_SEPARATOR = '/';

	Spreadsheet GetDataFromFile(const std::string& filename) const;
};
