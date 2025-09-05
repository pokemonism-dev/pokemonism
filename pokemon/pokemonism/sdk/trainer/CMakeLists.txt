cmake_minimum_required(VERSION 3.30)

project(pokemonism-trainer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_SDK_TRAINER_HEADER           lana.hh)

set(POKEMONISM_SDK_TRAINER_SOURCE           lana.cc)

add_library(pokemonism-trainer-dev          ${POKEMONISM_SDK_TRAINER_HEADER}
                                            ${POKEMONISM_SDK_TRAINER_SOURCE})

