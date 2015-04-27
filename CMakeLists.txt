cmake_minimum_required(VERSION 2.8.4)
project(gauss_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic -pedantic-errors")

set(SOURCE_FILES
	src/main.cpp
	src/Matrix.cpp src/Matrix.h
	)

add_executable(gauss ${SOURCE_FILES})



# cxxtest
find_package(CxxTest)
if(CXXTEST_FOUND)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test)
set(CXXTEST_USE_PYTHON TRUE)
include_directories(${CXXTEST_INCLUDE_DIR})
set(TEST_SOURCE_FILES
	test/test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/test.h
	)
enable_testing()
CXXTEST_ADD_TEST(unittest_gauss ${TEST_SOURCE_FILES})
add_executable(gauss_test ${TEST_SOURCE_FILE} ${SOURCE_FILES})
endif()
