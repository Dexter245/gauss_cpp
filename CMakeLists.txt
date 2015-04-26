cmake_minimum_required(VERSION 2.8.4)
project(gauss_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic -pedantic-errors")

set(SOURCE_FILES
	src/main.cpp)

add_executable(gauss_cpp ${SOURCE_FILES})