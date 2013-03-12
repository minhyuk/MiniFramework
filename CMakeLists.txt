cmake_minimum_required(VERSION 2.8)
#
#

PROJECT ( MiniFramework CXX )
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

SET (DEMO_SRC sample/Demo/Demo.cpp)
ADD_EXECUTABLE ( Demo  ${DEMO_SRC})



