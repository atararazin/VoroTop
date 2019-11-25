cmake_minimum_required(VERSION 3.6)
project(VoroTop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#find_package(Boost 1.58.0 COMPONENTS system filesystem REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})
#add_executable(BoostTest main.cpp)
#target_link_libraries(BoostTest ${Boost_LIBRARIES})

set(SOURCE_FILES main.cpp VoronoiCell.cpp Input.cpp FacesToGraph.cpp Graph/Face.cpp Graph/Edge.cpp Graph/Vertex.cpp Graph/Graph.cpp WeinbergVector.cpp WeinbergGraph.cpp WeinbergEdge.cpp WeinbergVertex.cpp)
add_executable(VoroTop ${SOURCE_FILES})