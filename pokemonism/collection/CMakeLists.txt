cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-collection-dev LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./src)

set(POKEMONISM_COLLECTION_SOURCE            src/pokemonism/collection/string.cc
                                            src/pokemonism/collection/stream.cc
                                            src/pokemonism/collection/stream/string.cc
                                            src/pokemonism/collection/container.cc
                                            src/pokemonism/collection/collection.cc
                                            src/pokemonism/collection/sequence.cc
                                            src/pokemonism/collection/continuous.cc
                                            src/pokemonism/collection/continuous/primitivable.cc
                                            src/pokemonism/collection/continuous/primitivable/unsigned.cc
                                            src/pokemonism/collection/continuous/primitivable/unsigned/char.cc
                                            src/pokemonism/collection/continuous/primitivable/unsigned/char/one.cc)

set(POKEMONISM_COLLECTION_HEADER            src/pokemonism/collection/string.hh
                                            src/pokemonism/collection/stream.hh
                                            src/pokemonism/collection/stream/string.hh
                                            src/pokemonism/collection/container.hh
                                            src/pokemonism/collection/collection.hh
                                            src/pokemonism/collection/sequence.hh
                                            src/pokemonism/collection/continuous.hh
                                            src/pokemonism/collection/continuous/primitivable.hh
                                            src/pokemonism/collection/continuous/primitivable/unsigned.hh
                                            src/pokemonism/collection/continuous/primitivable/unsigned/char.hh
                                            src/pokemonism/collection/continuous/primitivable/unsigned/char/one.hh)

add_library(pokemonism-collection-dev       ${POKEMONISM_COLLECTION_HEADER}
                                            ${POKEMONISM_COLLECTION_SOURCE})
