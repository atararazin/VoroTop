cmake_minimum_required(VERSION 3.6)
project(VoroTop)

##gprof flags
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
#SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
#SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
##

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")



##google test flags
#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)
##

set(SOURCE_FILES main.cpp Voro++/VoronoiCell.cpp Voro++/Input.cpp Graph/FacesToGraph.cpp Graph/Face.cpp Graph/Edge.cpp Graph/Vertex.cpp Graph/Graph.cpp WeinbergAlgorithm WeinbergAlgorithm/WeinbergVector.cpp WeinbergAlgorithm/WeinbergGraph/WeinbergGraph.cpp WeinbergAlgorithm/WeinbergGraph/WeinbergEdge.cpp WeinbergAlgorithm/WeinbergGraph/WeinbergVertex.cpp WeinbergAlgorithm/CanonicalVector.cpp WeinbergAlgorithm/CanonicalVector.h OutputFile.cpp OutputFile.h WeinbergAlgorithm/WeinbergAlgorithm.cpp WeinbergAlgorithm/Status.cpp WeinbergAlgorithm/Status.h .idea/GraphsFile.cpp .idea/GraphsFile.h GraphsFile.cpp GraphsFile.h ThreadPool.cpp ThreadPool.h WeinbergAlgorithm/WeinbergAlgorithm.h)
#tests/EdgeOrderingTest.cpp tests/WeinbergAlgorithmTest.cpp tests/NeighborsTest.cpp tests/VerticesCreationTest.cpp tests/GraphCreationTest.cpp tests/WeinbergVectorMethodsTests.cpp tests/TimeTest.cpp
add_executable(VoroTop ${SOURCE_FILES})

#target_link_libraries(VoroTop gtest gtest_main)
target_link_libraries(VoroTop pthread)

