cmake_minimum_required(VERSION 3.28.3)

project(meowth-dev CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(meowth-petilil               petilil.cc)
target_link_libraries(meowth-petilil        pokemon-dev petilil-dev)

add_executable(meowth-pokemon               pokemon.cc)
target_link_libraries(meowth-pokemon        pokemon-dev petilil-dev)