cmake_minimum_required(VERSION 3.30)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src ./)

add_subdirectory(src/train)

set(POKEMONISM_HEADER                       src/pokemonism.hh
                                            src/pokemonism/log.hh
                                            src/pokemonism/sync.hh
                                            src/pokemonism/event.hh
                                            src/pokemonism/generic/envelope.hh
                                            src/pokemonism/allocator.hh
                                            src/pokemonism/subscription.hh
                                            src/pokemonism/callable.hh
                                            src/pokemonism/runnable.hh
                                            src/pokemonism/cloneable.hh
                                            src/pokemonism/commandable.hh
                                            src/pokemonism/envelopeable.hh
                                            src/pokemonism/callbackable.hh
                                            src/pokemonism/primitivable.hh
                                            src/pokemonism/functionable.hh
                                            src/pokemonism/synchronizable.hh)

set(POKEMONISM_SOURCE                       src/pokemonism.cc
                                            src/pokemonism/log.cc
                                            src/pokemonism/sync.cc
                                            src/pokemonism/event.cc
                                            src/pokemonism/generic/envelope.cc
                                            src/pokemonism/allocator.cc
                                            src/pokemonism/subscription.cc
                                            src/pokemonism/callable.cc
                                            src/pokemonism/runnable.cc
                                            src/pokemonism/cloneable.cc
                                            src/pokemonism/commandable.cc
                                            src/pokemonism/envelopeable.cc
                                            src/pokemonism/callbackable.cc
                                            src/pokemonism/primitivable.cc
                                            src/pokemonism/functionable.cc
                                            src/pokemonism/synchronizable.cc)

add_library(pokemonism-dev                  ${POKEMONISM_HEADER}
                                            ${POKEMONISM_SOURCE})

add_subdirectory(pokemonism/supporter)
add_subdirectory(pokemonism/item)
add_subdirectory(pokemonism/pokemon)
add_subdirectory(pokemonism/psyduck)
add_subdirectory(pokemonism/petilil)

add_executable(pokemonism-cli               pokemonism.cc)


#
#
#include_directories(include src ./)
#
#set(POKEMONISM_INTERFACE_HEADER             src/pokemonism/interface/synchronizable.hh
#                                            src/pokemonism/interface/cloneable.hh
#                                            src/pokemonism/interface/runnable.hh
#                                            src/pokemonism/interface/envelopeable.hh
#                                            src/pokemonism/interface/callable.hh
#                                            src/pokemonism/interface/functionable.hh
#                                            src/pokemonism/interface/primitivable.hh
#                                            src/pokemonism/interface/observable.hh)
#
#set(POKEMONISM_INTERFACE_SOURCE             src/pokemonism/interface/synchronizable.cc
#                                            src/pokemonism/interface/cloneable.cc
#                                            src/pokemonism/interface/runnable.cc
#                                            src/pokemonism/interface/envelopeable.cc
#                                            src/pokemonism/interface/callable.cc
#                                            src/pokemonism/interface/functionable.cc
#                                            src/pokemonism/interface/primitivable.cc
#                                            src/pokemonism/interface/observable.cc)
#
#set(POKEMONISM_HEADER                       src/pokemonism/log.hh
#                                            src/pokemonism/event.hh
#                                            src/pokemonism/command.hh
#                                            src/pokemonism/allocator.hh
#                                            src/pokemonism/envelope.hh
#                                            src/pokemonism/exception.hh
#                                            src/pokemonism/subscription.hh)
#
#set(POKEMONISM_SOURCE                       src/pokemonism/log.cc
#                                            src/pokemonism/event.cc
#                                            src/pokemonism/command.cc
#                                            src/pokemonism/allocator.cc
#                                            src/pokemonism/envelope.cc
#                                            src/pokemonism/exception.cc
#                                            src/pokemonism/subscription.cc)
#
#add_library(pokemonism-dev                  ${POKEMONISM_INTERFACE_HEADER}
#                                            ${POKEMONISM_INTERFACE_SOURCE}
#                                            ${POKEMONISM_HEADER}
#                                            ${POKEMONISM_SOURCE})
#
#add_subdirectory(pokemonism/pokemon)
#add_subdirectory(pokemonism/petilil)
#
#add_subdirectory(pokemonism/meowth)
#
#add_executable(pokemonism-cli               pokemonism.cc)
#target_link_libraries(pokemonism-cli        pokemonism-dev)


#add_subdirectory(pokemonism/meowth)
#
#add_subdirectory(pokemonism/pokemon)
#add_subdirectory(pokemonism/psyduck)
#add_subdirectory(pokemonism/sprigatito)
#add_subdirectory(pokemonism/ralts)
#add_subdirectory(pokemonism/latios)
#add_subdirectory(pokemonism/petilil)

#set(POKEMONISM_ROOT_HEADER          include/pokemonism.hh)
#
#set(POKEMONISM_ROOT_SOURCE          src/pokemonism.cc)
#
#set(POKEMONISM_POKEMON_HEADER       pokemonism/pokemon.hh
#                                    pokemonism/meowth.hh
#                                    pokemonism/psyduck.hh
#                                    pokemonism/sprigatito.hh
#                                    pokemonism/ralts.hh
#                                    pokemonism/latios.hh
#                                    pokemonism/petilil.hh)
#
#set(POKEMONISM_POKEMON_SOURCE       pokemonism/pokemon.cc
#                                    pokemonism/meowth.cc
#                                    pokemonism/psyduck.cc
#                                    pokemonism/sprigatito.cc
#                                    pokemonism/ralts.cc
#                                    pokemonism/latios.cc
#                                    pokemonism/petilil.cc)
#
#add_executable(pokemonism-dev       ${POKEMONISM_ROOT_HEADER}
#                                    ${POKEMONISM_ROOT_SOURCE}
#                                    ${POKEMONISM_POKEMON_HEADER}
#                                    ${POKEMONISM_POKEMON_SOURCE})
#
#add_subdirectory(pokemonism/meowth/persian)
