cmake_minimum_required(VERSION 3.30)

project(pokemon LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(POKEMON_HEADER                          ../pokemon.hh
                                            ball.hh
                                            battle.hh
                                            faint.hh)

set(POKEMON_SOURCE                          ../pokemon.cc
                                            ball.cc
                                            battle.cc
                                            faint.cc)

add_library(pokemon-dev                     ${POKEMON_HEADER}
                                            ${POKEMON_SOURCE})

