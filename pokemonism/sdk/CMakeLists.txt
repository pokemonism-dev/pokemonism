cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_SDK_SOURCE               src/pokemonism/sdk/log.cc
                                        src/pokemonism/sdk/string.cc
                                        src/pokemonism/sdk/stream.cc
                                        src/pokemonism/sdk/linked/list.cc
                                        src/pokemonism/sdk/typographer.cc
                                        src/pokemonism/sdk/application.cc
                                        src/pokemonism/sdk/exception.cc
                                        src/pokemonism/sdk/allocator.cc
                                        src/pokemonism/sdk/memorizer.cc
                                        src/pokemonism/sdk/memorizer/primitivable.cc
                                        src/pokemonism/sdk/memorizer/primitivable/one.cc)

set(POKEMONISM_SDK_HEADER               src/pokemonism/sdk/log.hh
                                        src/pokemonism/sdk/string.hh
                                        src/pokemonism/sdk/stream.hh
                                        src/pokemonism/sdk/linked/list.hh
                                        src/pokemonism/sdk/typographer.hh
                                        src/pokemonism/sdk/application.hh
                                        src/pokemonism/sdk/exception.hh
                                        src/pokemonism/sdk/allocator.hh
                                        src/pokemonism/sdk/memorizer.hh
                                        src/pokemonism/sdk/memorizer/primitivable.hh
                                        src/pokemonism/sdk/memorizer/primitivable/one.hh)

add_library(pokemonism-sdk              ${POKEMONISM_SDK_SOURCE}
                                        ${POKEMONISM_SDK_HEADER})


