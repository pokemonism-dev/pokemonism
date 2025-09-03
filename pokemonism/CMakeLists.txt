cmake_minimum_required(VERSION 3.28.3)

project(pokemon-dev CXX)

set(CMAKE_CXX_STANDARD 23)

set(POKEMON_HEADER                          pokemon.hh
                                            petilil.hh)

set(POKEMON_SOURCE                          pokemon.cc
                                            petilil.cc)

add_library(pokemon-dev                     ${POKEMON_HEADER}
                                            ${POKEMON_SOURCE})