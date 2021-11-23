include_directories(GoogleTest)
include_directories("{CMAKE_SOURCE_DIR}/math")
enable_testing()
add_executable(${PROJECT_NAME} main.cpp Vec2d_test.cpp)
target_link_libraries(${PROJECT_NAME} gtest pthread MODULE_MATH)


