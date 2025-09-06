cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-trainer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./)

set(POKEMONISM_TRAINER_HEADER           pokemonism/trainer/lana.hh)

set(POKEMONISM_TRAINER_SOURCE           pokemonism/trainer/lana.cc)

add_library(pokemonism-trainer-dev      ${POKEMONISM_TRAINER_HEADER}
                                        ${POKEMONISM_TRAINER_SOURCE})
