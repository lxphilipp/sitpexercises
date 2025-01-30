project(${PROJECT_NAME}_solution)

# Hauptprogramm der Solution
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Tests der Solution
add_executable(
        ${PROJECT_NAME}_test
        test/RenderConfigTests.cpp
)
target_include_directories(${PROJECT_NAME}_test PRIVATE include)
target_link_libraries(
        ${PROJECT_NAME}_test
        GTest::gtest_main
)

gtest_discover_tests(${PROJECT_NAME}_test)