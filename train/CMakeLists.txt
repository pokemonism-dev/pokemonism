cmake_minimum_required(VERSION 3.30)

project(pokemonism-train LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(pokemonism-pokemon-train             pokemonism-pokemon-train.cc)

add_executable(pokemonism-trainer-train             pokemonism-trainer-train.cc)
target_link_libraries(pokemonism-trainer-train      pokemonism-trainer-dev pokemonism-pokemon-dev)
