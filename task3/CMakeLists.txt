cmake_minimum_required(VERSION 3.10)
project(task3)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

add_subdirectory(solution)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Hauptprogramm
add_executable(${PROJECT_NAME} src/main.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Tests
add_executable(
        ${PROJECT_NAME}_test
        test/BasicSITPTests.cpp
        test/AdvancedSITPTests.cpp
)
target_include_directories(${PROJECT_NAME}_test PRIVATE include)
target_link_libraries(
        ${PROJECT_NAME}_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)