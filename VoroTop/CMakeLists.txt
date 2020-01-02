cmake_minimum_required(VERSION 3.6)
project(VoroTop)

##
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
##

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp tests/EdgeOrderingTest.cpp tests/WeinbergAlgorithmTest.cpp Voro++/VoronoiCell.cpp Voro++/Input.cpp Graph/FacesToGraph.cpp Graph/Face.cpp Graph/Edge.cpp Graph/Vertex.cpp Graph/Graph.cpp WeinbergAlgorithm WeinbergAlgorithm/WeinbergVector.cpp WeinbergAlgorithm/WeinbergGraph/WeinbergGraph.cpp WeinbergAlgorithm/WeinbergGraph/WeinbergEdge.cpp WeinbergAlgorithm/WeinbergGraph/WeinbergVertex.cpp tests/NeighborsTest.cpp .idea/Complex.cpp tests/VerticesCreationTest.cpp tests/GraphCreationTest.cpp WeinbergAlgorithm/CanonicalVector.cpp WeinbergAlgorithm/CanonicalVector.h WeinbergAlgorithm/Direction.cpp WeinbergAlgorithm/Direction.h OutputFile.cpp OutputFile.h tests/WeinbergVectorMethodsTests.cpp tests/TimeTest.cpp)
add_executable(VoroTop ${SOURCE_FILES} tests/NeighborsTest.cpp)
target_link_libraries(VoroTop gtest gtest_main)
