cmake_minimum_required(VERSION 3.6)
project(VoroTop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp VoronoiCell.cpp Input.cpp FacesToGraph.cpp Face.cpp Edge.cpp Vertex.cpp GraphsContainer.cpp Graph.cpp)
add_executable(VoroTop ${SOURCE_FILES})