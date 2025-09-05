cmake_minimum_required(VERSION 3.30)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./)

set(POKEMONISM_HEADER                       pokemonism.hh
                                            pokemonism/log.hh
                                            pokemonism/sync.hh
                                            pokemonism/event.hh
                                            pokemonism/generic/envelope.hh
                                            pokemonism/allocator.hh
                                            pokemonism/subscription.hh
                                            pokemonism/callable.hh
                                            pokemonism/runnable.hh
                                            pokemonism/cloneable.hh
                                            pokemonism/commandable.hh
                                            pokemonism/envelopeable.hh
                                            pokemonism/callbackable.hh
                                            pokemonism/primitivable.hh
                                            pokemonism/functionable.hh
                                            pokemonism/synchronizable.hh
                                            pokemonism/linked/list.hh)

set(POKEMONISM_SOURCE                       pokemonism.cc
                                            pokemonism/log.cc
                                            pokemonism/sync.cc
                                            pokemonism/event.cc
                                            pokemonism/generic/envelope.cc
                                            pokemonism/allocator.cc
                                            pokemonism/subscription.cc
                                            pokemonism/callable.cc
                                            pokemonism/runnable.cc
                                            pokemonism/cloneable.cc
                                            pokemonism/commandable.cc
                                            pokemonism/envelopeable.cc
                                            pokemonism/callbackable.cc
                                            pokemonism/primitivable.cc
                                            pokemonism/functionable.cc
                                            pokemonism/synchronizable.cc
                                            pokemonism/linked/list.cc)

add_library(pokemonism-dev                  ${POKEMONISM_HEADER}
                                            ${POKEMONISM_SOURCE})
