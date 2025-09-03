cmake_minimum_required(VERSION 3.28.3)

project(pokemon-dev CXX)

set(CMAKE_CXX_STANDARD 23)

set(POKEMON_MODULE                          ../pokemon.ixx)

set(POKEMON_ROOT_SOURCE                     )

set(POKEMON_SOURCE                          ball.cc)

add_library(pokemon-dev                     ${POKEMON_MODULE}
                                            ${POKEMON_ROOT_SOURCE}
                                            ${POKEMON_SOURCE})

