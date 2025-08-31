cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(include src pokemonism ./)

add_subdirectory(pokemonism/meowth)

add_subdirectory(pokemonism/pokemon)
add_subdirectory(pokemonism/latios)
add_subdirectory(pokemonism/wattrel)
add_subdirectory(pokemonism/psyduck)
add_subdirectory(pokemonism/mareep)
add_subdirectory(pokemonism/sprigatito)

set(POKEMONISM_ROOT_HEADER          include/pokemonism.hh)

set(POKEMONISM_ROOT_SOURCE          src/pokemonism.cc)

set(POKEMONISM_POKEMON_HEADER       pokemonism/pokemon.hh
                                    pokemonism/meowth.hh
                                    pokemonism/latios.hh
                                    pokemonism/psyduck.hh
                                    pokemonism/mareep.hh
                                    pokemonism/wattrel.hh
                                    pokemonism/sprigatito.hh)

set(POKEMONISM_POKEMON_SOURCE       pokemonism/pokemon.cc
                                    pokemonism/meowth.cc
                                    pokemonism/latios.cc
                                    pokemonism/psyduck.cc
                                    pokemonism/mareep.cc
                                    pokemonism/wattrel.cc
                                    pokemonism/sprigatito.cc)

add_executable(pokemonism-dev       ${POKEMONISM_ROOT_HEADER}
                                    ${POKEMONISM_ROOT_SOURCE}
                                    ${POKEMONISM_POKEMON_HEADER}
                                    ${POKEMONISM_POKEMON_SOURCE})

add_subdirectory(pokemonism/meowth/persian)
