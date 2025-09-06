cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./)

add_subdirectory(pokemonism/sdk)

set(POKEMONISM_HEADER                       pokemonism.hh)

set(POKEMONISM_SOURCE                       pokemonism.cc)

add_library(pokemonism-dev                  ${POKEMONISM_HEADER}
                                            ${POKEMONISM_SOURCE})

add_subdirectory(train/sdk)

add_executable(pokemonism-cli               pokemonism-cli.cc)
