cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(include src pokemonism ./)

add_subdirectory(pokemonism/pokemon)
add_subdirectory(pokemonism/sprigatito)
add_subdirectory(pokemonism/psyduck)
add_subdirectory(pokemonism/mareep)
add_subdirectory(pokemonism/latios)

set(POKEMONISM_ROOT_HEADER          include/pokemonism.hh)

set(POKEMONISM_ROOT_SOURCE          src/pokemonism.cc)

set(POKEMONISM_HEADER               src/primitivable.hh
                                    src/synchronizable.hh)

set(POKEMONISM_SOURCE               src/primitivable.cc
                                    src/synchronizable.cc)

set(POKEMONISM_POKEMON_HEADER       pokemonism/pokemon.hh
                                    pokemonism/latios.hh
                                    pokemonism/mareep.hh
                                    pokemonism/psyduck.hh
                                    pokemonism/sprigatito.hh)

set(POKEMONISM_POKEMON_SOURCE       pokemonism/pokemon.cc
                                    pokemonism/latios.cc
                                    pokemonism/mareep.cc
                                    pokemonism/psyduck.cc
                                    pokemonism/sprigatito.cc)

set(POKEMONISM_IMPLEMENT_SOURCE     )

add_executable(pokemonism-dev       ${POKEMONISM_ROOT_HEADER}
                                    ${POKEMONISM_ROOT_SOURCE}
                                    ${POKEMONISM_HEADER}
                                    ${POKEMONISM_SOURCE}
                                    ${POKEMONISM_POKEMON_HEADER}
                                    ${POKEMONISM_POKEMON_SOURCE}
                                    ${POKEMONISM_IMPLEMENT_SOURCE})

add_subdirectory(pokemonism/meowth/persian)