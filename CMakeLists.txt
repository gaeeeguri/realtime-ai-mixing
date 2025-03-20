cmake_minimum_required(VERSION 3.16)
project(DSP_Library)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Path
include_directories(include)
add_executable(DSP_Library src/main.cpp)

