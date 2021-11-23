cmake_minimum_required(VERSION 2.80)
project(Learning_Apollo)


include(GoogleTest)

#设置文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(commons)
add_subdirectory(commons/math)

