cmake_minimum_required(VERSION 3.15)
project(AdventOfCode2025 LANGUAGES CXX)

# -------------------------------
# C++ Settings
# -------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------
# Include directories
# -------------------------------
include_directories(include)

# -------------------------------
# Shared library
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
# Fetch Catch2
# -------------------------------
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(Catch2)

# -------------------------------
# Test executable
# -------------------------------
add_executable(test_day03
    tests/test_day03.cpp
)
target_link_libraries(test_day03 PRIVATE compute_lib Catch2::Catch2WithMain)
add_test(NAME JoltageTests COMMAND test_day03)

# -------------------------------
# Custom targets for convenience
# -------------------------------

# Run each day
add_custom_target(run_day01
    COMMAND day01
    DEPENDS day01
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_target(run_day02
    COMMAND day02
    DEPENDS day02
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_target(run_day03
    COMMAND day03
    DEPENDS day03
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Run all days
add_custom_target(run_all_days
    COMMAND day01
    COMMAND day02
    COMMAND day03
    DEPENDS day01 day02 day03
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# Run tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_day03
)