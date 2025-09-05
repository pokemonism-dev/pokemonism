cmake_minimum_required(VERSION 3.30)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./ trainer)

add_subdirectory(pokemonism/sdk)

set(POKEMONISM_HEADER                       pokemonism.hh
                                            pokemonism/pokemon.hh
                                            pokemonism/trainer.hh)

set(POKEMONISM_SOURCE                       pokemonism.cc
                                            pokemonism/pokemon.cc
                                            pokemonism/trainer.cc)

add_library(pokemonism-dev                  ${POKEMONISM_HEADER}
                                            ${POKEMONISM_SOURCE})


add_subdirectory(trainer)

add_subdirectory(train/trainer)

add_executable(pokemonism-cli               pokemonism-cli.cc)
