cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_SDK_SOURCE               src/pokemonism/sdk/log.cc
                                        src/pokemonism/sdk/application.cc
                                        src/pokemonism/sdk/exception.cc
                                        src/pokemonism/sdk/allocator.cc)

set(POKEMONISM_SDK_HEADER               src/pokemonism/sdk/log.hh
                                        src/pokemonism/sdk/application.hh
                                        src/pokemonism/sdk/exception.hh
                                        src/pokemonism/sdk/allocator.hh)

add_library(pokemonism-sdk              ${POKEMONISM_SDK_SOURCE}
                                        ${POKEMONISM_SDK_HEADER})

