cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(automata-checkers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
               src/main.cpp
               src/App/IInputOutputAdapter.h
               src/Infrastructure/CSV/CInputOutputAdapter.cpp
               src/Infrastructure/CSV/CInputOutputAdapter.h
               src/App/CVisualizerService.cpp
               src/App/CVisualizerService.h
               src/App/IGraphVisualizer.h
               src/Infrastructure/Graphviz/CGraphVisualizer.cpp
               src/Infrastructure/Graphviz/CGraphVisualizer.h)
