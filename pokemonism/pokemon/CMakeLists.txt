cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_HEADER                  ../pokemon.hh
                                    object.hh
                                    exception.hh)

set(POKEMON_SOURCE                  ../pokemon.cc
                                    object.cc
                                    exception.cc)

add_library(pokemon-dev             ${POKEMON_HEADER}
                                    ${POKEMON_SOURCE})
