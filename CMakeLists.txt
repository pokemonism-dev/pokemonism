cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./ trainer pokemon professor)

add_subdirectory(pokemonism/sdk)

set(POKEMONISM_HEADER                       pokemonism.hh
                                            pokemonism/monsterizable.hh
                                            pokemonism/trainerizable.hh
                                            pokemonism/toolizable.hh
                                            pokemonism/tool.hh
                                            pokemonism/faint.hh
                                            pokemonism/battle.hh
                                            pokemonism/pokemon.hh
                                            pokemonism/professor.hh
                                            pokemonism/pokemon/center.hh
                                            pokemonism/trainer.hh)

set(POKEMONISM_SOURCE                       pokemonism.cc
                                            pokemonism/monsterizable.cc
                                            pokemonism/trainerizable.cc
                                            pokemonism/toolizable.cc
                                            pokemonism/tool.cc
                                            pokemonism/faint.cc
                                            pokemonism/battle.cc
                                            pokemonism/pokemon.cc
                                            pokemonism/professor.cc
                                            pokemonism/pokemon/center.cc
                                            pokemonism/trainer.cc)

add_library(pokemonism-dev                  ${POKEMONISM_HEADER}
                                            ${POKEMONISM_SOURCE})


add_subdirectory(trainer)
add_subdirectory(tool)
add_subdirectory(professor)

add_subdirectory(pokemon/pokemonism/pokemon/petilil)

add_subdirectory(train/sdk)
add_subdirectory(train/trainer)

add_executable(pokemonism-cli               pokemonism-cli.cc)
