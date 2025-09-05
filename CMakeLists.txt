cmake_minimum_required(VERSION 3.30)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./ trainer pokemon)

add_subdirectory(pokemonism/sdk)

set(POKEMONISM_HEADER                       pokemonism.hh
                                            pokemonism/monsterizable.hh
                                            pokemonism/trainerizable.hh
                                            pokemonism/faint.hh
                                            pokemonism/battle.hh
                                            pokemonism/pokemon.hh
                                            pokemonism/pokemon/center.hh
                                            pokemonism/trainer.hh)

set(POKEMONISM_SOURCE                       pokemonism.cc
                                            pokemonism/monsterizable.cc
                                            pokemonism/trainerizable.cc
                                            pokemonism/faint.cc
                                            pokemonism/battle.cc
                                            pokemonism/pokemon.cc
                                            pokemonism/pokemon/center.cc
                                            pokemonism/trainer.cc)

add_library(pokemonism-dev                  ${POKEMONISM_HEADER}
                                            ${POKEMONISM_SOURCE})


add_subdirectory(trainer)

add_subdirectory(pokemon/pokemonism/pokemon/petilil)

add_subdirectory(train/trainer)

add_executable(pokemonism-cli               pokemonism-cli.cc)
