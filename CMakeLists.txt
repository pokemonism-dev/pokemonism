cmake_minimum_required(VERSION 3.30)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(pokemonism/)

add_executable(pokemonism-cli               pokemonism.cc)

add_subdirectory(pokemonism)
