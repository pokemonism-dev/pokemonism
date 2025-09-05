cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(persian-latios-engine            persian-latios-engine.cc)
target_link_libraries(persian-latios-engine     latios-dev)
