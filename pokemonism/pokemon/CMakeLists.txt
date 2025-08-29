cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_ROOT_HEADER             ../pokemon.hh)

set(POKEMON_ROOT_SOURCE             ../pokemon.cc)

set(POKEMON_HEADER                  object.hh
                                    exception.hh
                                    allocator.hh)

set(POKEMON_SOURCE                  object.cc
                                    exception.cc
                                    allocator.cc)

add_library(pokemon-dev             ${POKEMON_ROOT_HEADER}
                                    ${POKEMON_ROOT_SOURCE}
                                    ${POKEMON_HEADER}
                                    ${POKEMON_SOURCE})
