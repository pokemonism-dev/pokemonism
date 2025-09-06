cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(train-pokemonism-sdk-engine              train-pokemonism-sdk-engine.cc)
target_link_libraries(train-pokemonism-sdk-engine       pokemonism-dev pokemonism-sdk)
