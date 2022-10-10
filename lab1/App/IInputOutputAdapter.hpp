#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct InitialStateAndInputSymbol
{
	std::string state;
	std::string symbol;
};

template <>
struct std::hash<InitialStateAndInputSymbol>
{
	std::size_t operator()(InitialStateAndInputSymbol const& key) const
	{
		return std::hash<std::string>()(key.state) ^ std::hash<std::string>()(key.symbol);
	}
};

struct DestinationStateAndSignal
{
	std::string state;
	std::string signal;
};

struct MealyAutomaton
{
	std::vector<std::string> states;
	std::vector<std::string> inputSymbols;
	std::unordered_map<InitialStateAndInputSymbol, DestinationStateAndSignal> moves;
};

struct MooreAutomaton
{
	std::vector<std::string> states;
	std::vector<std::string> inputSymbols;
	std::unordered_map<std::string, std::string> stateSignals;
	std::unordered_map<InitialStateAndInputSymbol, std::string> moves;
};

class IInputOutputAdapter
{
public:
	virtual MealyAutomaton GetMealy(std::string const& filename) = 0;
	virtual MooreAutomaton GetMoore(std::string const& filename) = 0;

	virtual ~IInputOutputAdapter() = default;
};

using IInputOutputAdapterPtr = std::unique_ptr<IInputOutputAdapter>;
