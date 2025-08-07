cmake_minimum_required(VERSION 3.21.4)
project(ChaosEngine VERSION 0.0.1)

# A = Alpha
# B = Beta
# R = Release
# D = Delta
# Delta version are version unfinishes after first release
set(PROJECT_VERSION_TAG "A")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (PROJECT_VERSION_TAG STREQUAL "R")
	set(PROJECT_VERSION_STRING "${PROJECT_VERSION}")
else()
	set(PROJECT_VERSION_STRING "${PROJECT_VERSION_TAG}${PROJECT_VERSION}")
endif()

configure_file(
	${CMAKE_CURRENT_LIST_DIR}/ChaosInfo.hpp.in
	${CMAKE_CURRENT_LIST_DIR}/ChaosInfo.hpp
)

option(BuildExample "Build a demostration code" OFF)

add_library(ChCore SHARED
	engine.cpp
	LogSys/log.cpp
	LogSys/err.cpp
)

if (BuildDemo)
	add_subdirectory(demo)
endif()

target_include_directories(ChCore PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
