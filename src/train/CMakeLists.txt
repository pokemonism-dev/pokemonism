cmake_minimum_required(VERSION 3.30)

project(train LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(pokemonism-train-petilil             train-petilil.cc)
target_link_libraries(pokemonism-train-petilil      pokemonism-pokemon-dev pokemonism-petilil-dev)