cmake_minimum_required(VERSION 3.16)
project(DSP_Library)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Path
include_directories(include)
add_executable(DSP_Library
    src/main.cpp
    src/SignalGenerator.cpp
    src/SignalProcessor.cpp
)

# Google Test
enable_testing()
add_subdirectory(external/googletest)
include_directories(external/googletest/googletest/include)

# Run Test
add_executable(runTests 
    tests/main.cpp
    tests/test_SignalGenerator.cpp
    tests/test_SignalProcessor.cpp
    tests/test_FilterProcessor.cpp
    src/SignalGenerator.cpp
    src/SignalProcessor.cpp
    src/FilterProcessor.cpp
)
target_link_libraries(runTests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)