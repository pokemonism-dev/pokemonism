cmake_minimum_required(VERSION 3.30)

project(pokemonism-pokemon LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_SDK_POKEMON_HEADER           pokemonism/sdk/faint.hh
                                            pokemonism/sdk/item.hh
                                            pokemonism/sdk/pokeball.hh
                                            pokemonism/sdk/pokemon.hh
                                            pokemonism/sdk/stadium.hh
                                            pokemonism/sdk/tool.hh
                                            pokemonism/sdk/trainer.hh)

set(POKEMONISM_SDK_POKEMON_SOURCE           pokemonism/sdk/faint.cc
                                            pokemonism/sdk/item.cc
                                            pokemonism/sdk/pokeball.cc
                                            pokemonism/sdk/pokemon.cc
                                            pokemonism/sdk/stadium.cc
                                            pokemonism/sdk/tool.cc
                                            pokemonism/sdk/trainer.cc)

add_library(pokemonism-pokemon-dev          ${POKEMONISM_SDK_POKEMON_HEADER}
                                            ${POKEMONISM_SDK_POKEMON_SOURCE})

add_subdirectory(pokemonism/sdk/trainer)
