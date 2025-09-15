cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-interface-dev LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./src)

set(POKEMONISM_INTERFACE_SOURCE             src/pokemonism/virtualable.cc
                                            src/pokemonism/observable.cc
                                            src/pokemonism/observerable.cc
                                            src/pokemonism/runnable.cc
                                            src/pokemonism/callable.cc
                                            src/pokemonism/lambdable.cc
                                            src/pokemonism/cloneable.cc
                                            src/pokemonism/containable.cc
                                            src/pokemonism/continuable.cc
                                            src/pokemonism/collectable.cc
                                            src/pokemonism/sequenceable.cc
                                            src/pokemonism/streamable.cc
                                            src/pokemonism/envelopeable.cc
                                            src/pokemonism/primitivable.cc
                                            src/pokemonism/communicatable.cc
                                            src/pokemonism/synchronizable.cc
                                            src/pokemonism/applicationable.cc)

set(POKEMONISM_INTERFACE_HEADER             src/pokemonism/virtualable.hh
                                            src/pokemonism/observable.hh
                                            src/pokemonism/observerable.hh
                                            src/pokemonism/runnable.hh
                                            src/pokemonism/callable.hh
                                            src/pokemonism/lambdable.hh
                                            src/pokemonism/cloneable.hh
                                            src/pokemonism/containable.hh
                                            src/pokemonism/continuable.hh
                                            src/pokemonism/collectable.hh
                                            src/pokemonism/sequenceable.hh
                                            src/pokemonism/streamable.hh
                                            src/pokemonism/envelopeable.hh
                                            src/pokemonism/primitivable.hh
                                            src/pokemonism/communicatable.hh
                                            src/pokemonism/synchronizable.hh
                                            src/pokemonism/applicationable.hh)

add_library(pokemonism-interface-dev        ${POKEMONISM_INTERFACE_SOURCE}
                                            ${POKEMONISM_INTERFACE_HEADER})
