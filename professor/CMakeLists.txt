cmake_minimum_required(VERSION 3.30)

project(pokemonism-professor LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./)

set(POKEMONISM_PROFESSOR_HEADER             pokemonism/professor/oak.hh
                                            pokemonism/professor/oak/tools/randomizer.hh)

set(POKEMONISM_PROFESSOR_SOURCE             pokemonism/professor/oak.cc
                                            pokemonism/professor/oak/tools/randomizer.cc)

add_library(pokemonism-professor-dev        ${POKEMONISM_PROFESSOR_HEADER}
                                            ${POKEMONISM_PROFESSOR_SOURCE})
