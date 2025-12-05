cmake_minimum_required(VERSION 3.15)
project(AdventOfCode2025 LANGUAGES CXX)

# -------------------------------
# C++ settings
# -------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------
# Include directories
# -------------------------------
include_directories(include)

# -------------------------------
# Shared library with utility functions
# -------------------------------
add_library(compute_lib
    src/range_tools.cpp
    src/joltage.cpp
)
target_include_directories(compute_lib PUBLIC include)

# -------------------------------
# Day executables
# -------------------------------
add_executable(day01 src/day01.cpp)
target_link_libraries(day01 PRIVATE compute_lib)

add_executable(day02 src/day02.cpp)
target_link_libraries(day02 PRIVATE compute_lib)

add_executable(day03 src/day03.cpp)
target_link_libraries(day03 PRIVATE compute_lib)

# -------------------------------
# Enable testing
# -------------------------------
enable_testing()

# -------------------------------
# Catch2
# -------------------------------
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0  # or latest stable tag
)

FetchContent_MakeAvailable(Catch2)

# -------------------------------
# Test executable
# -------------------------------
add_executable(test_day03
    tests/test_day03.cpp
)
target_link_libraries(test_day03 PRIVATE compute_lib Catch2::Catch2WithMain)

# Register test with CTest
add_test(NAME JoltageTests COMMAND test_day03)