#include "./App/CVisualizerService.h"
#include "Infrastructure/CSV/CInputOutputAdapter.h"
#include "Infrastructure/Graphviz/CGraphVisualizer.h"
#include <iostream>

inline const std::string_view MEALY_TYPE = "mealy";
inline const std::string_view MOORE_TYPE = "moore";

enum class AutomatonType
{
	Mealy,
	Moore,
};

struct Args
{
	AutomatonType automatonType;
	std::string inputFilename;
	std::string outputFilename;
};

Args ParseArgs(int argc, char** argv)
{
	if (argc != 4)
	{
		throw std::invalid_argument("usage: lab1-checker [mealy|moore] [input csv filename] [output dot filename]");
	}

	AutomatonType type;
	auto const strType = std::string_view(argv[1]);
	if (strType == MEALY_TYPE)
	{
		type = AutomatonType::Mealy;
	}
	else if (strType == MOORE_TYPE)
	{
		type = AutomatonType::Mealy;
	}
	else
	{
		throw std::invalid_argument("invalid automaton type, choose 'mealy' or 'moore'");
	}

	return {
		.automatonType = type,
		.inputFilename = argv[2],
		.outputFilename = argv[3],
	};
}

int main(int argc, char** argv)
{
	try
	{
		auto const args = ParseArgs(argc, argv);

		CVisualizerService service(
			std::make_unique<CInputOutputAdapter>(),
			std::make_unique<CGraphVisualizer>());

		switch (args.automatonType)
		{
		case AutomatonType::Mealy:
			service.DrawMealy(args.inputFilename, args.outputFilename);
			break;
		case AutomatonType::Moore:
			service.DrawMoore(args.inputFilename, args.outputFilename);
			break;
		}
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
