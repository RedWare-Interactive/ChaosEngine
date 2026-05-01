cmake_minimum_required(VERSION 3.21.4)
project(ChaosEngine VERSION 0.0.1)

# A = Alpha
set(PROJECT_VERSION_TAG "A")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ChCore SHARED
	engine.cpp
	utils/logger.cpp
)

target_include_directories(ChCore PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory(demo)
