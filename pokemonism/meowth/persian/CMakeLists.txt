cmake_minimum_required(VERSION 3.28.3)

project(persian CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(persian-wattrel-engine           persian-wattrel-engine.cc)
target_link_libraries(persian-wattrel-engine    wattrel-dev)
