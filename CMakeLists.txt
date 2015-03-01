cmake_minimum_required(VERSION 2.8.4)
project(AhaAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
aux_source_directory(. DIR_SRCS)
# 添加 子目录
add_subdirectory(sort)
add_subdirectory(list)
# 指定生成目标
add_executable(AhaAlgorithms main.cpp)
# 添加链接库
target_link_libraries(AhaAlgorithms Sort)
target_link_libraries(AhaAlgorithms List)
