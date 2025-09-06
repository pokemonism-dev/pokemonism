cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(train-pokemonism-trainer         train-pokemonism-trainer.cc)
target_link_libraries(train-pokemonism-trainer  pokemonism-trainer-dev pokemonism-dev)