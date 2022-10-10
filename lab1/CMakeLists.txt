cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1
               main.cpp
               App/IInputOutputAdapter.hpp
               Infrastructure/CSV/CInputOutputAdapter.cpp
               Infrastructure/CSV/CInputOutputAdapter.h App/CVisualizerService.cpp App/CVisualizerService.h App/IGraphVisualizer.h Infrastructure/Graphviz/CGraphVisualizer.cpp Infrastructure/Graphviz/CGraphVisualizer.h)
