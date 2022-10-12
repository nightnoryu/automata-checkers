#include "CInputOutputAdapter.h"
#include <iostream>
#include <fstream>
#include <sstream>

CInputOutputAdapter::Spreadsheet CInputOutputAdapter::GetDataFromFile(const std::string& filename)
{
	std::ifstream input(filename);
	if (!input.is_open())
	{
		throw std::runtime_error("failed to open input file for reading");
	}

	Spreadsheet spreadsheet;
	std::string row;
	std::string cell;

	while(std::getline(input, row))
	{
		std::istringstream iss(row);
		std::vector<std::string> rows;

		while(std::getline(iss, cell, ','))
		{
			rows.push_back(cell);
		}

		spreadsheet.push_back(rows);
	}

	return spreadsheet;
}

MealyAutomaton CInputOutputAdapter::GetMealy(const std::string& filename)
{
	Spreadsheet spreadsheet = GetDataFromFile(filename);

	std::vector<std::string> states;
	std::vector<std::string> inputSymbols;
	MealyMoves moves;

	std::vector<std::string> elements;

	for (int rowIndex = 0; rowIndex < spreadsheet.size(); ++rowIndex)
	{
		for (int columnIndex = 0; columnIndex < spreadsheet[rowIndex].size(); ++columnIndex)
		{
			if (rowIndex == 0 && columnIndex == 0)
			{
				continue;
			}

			if (rowIndex == 0)
			{
				states.push_back(spreadsheet[rowIndex][columnIndex]);
				continue;
			}

			if (columnIndex == 0)
			{
				inputSymbols.push_back(spreadsheet[rowIndex][columnIndex]);
				continue;
			}

			std::stringstream ss(spreadsheet[rowIndex][columnIndex]);
			std::string element;
			while (std::getline(ss, element, '/'))
			{
				elements.push_back(element);
			}

			moves.insert({
				{spreadsheet[0][columnIndex], spreadsheet[rowIndex][0]},
				{elements[0], elements[1]}
			});

			elements.clear();
		}
	}

	return {
		.states = states,
		.inputSymbols = inputSymbols,
		.moves = moves,
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
