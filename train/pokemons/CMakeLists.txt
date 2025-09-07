cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(train-togepi                     train-togepi.cc)
target_link_libraries(train-togepi              pokemonism-sdk pokemonism-dev)

add_executable(train-togepi-evolve              train-togepi-evolve.cc)
target_link_libraries(train-togepi-evolve       pokemonism-sdk pokemonism-dev)

add_executable(train-togetic                    train-togetic.cc)
target_link_libraries(train-togetic             pokemonism-sdk pokemonism-dev)
