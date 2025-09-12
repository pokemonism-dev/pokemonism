cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-window LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_WINDOW_SOURCE            src/pokemonism/window.cc
                                        src/pokemonism/window/platform.cc
                                        src/pokemonism/window/config.cc
                                        src/pokemonism/window/lib.cc
                                        src/pokemonism/window/vulkan/config.cc
                                        src/pokemonism/window/cocoa/lib.cc
                                        src/pokemonism/window/cocoa/config.cc)

set(POKEMONISM_WINDOW_HEADER            src/pokemonism/window.hh
                                        src/pokemonism/window/platform.hh
                                        src/pokemonism/window/config.hh
                                        src/pokemonism/window/lib.hh
                                        src/pokemonism/window/vulkan/config.hh
                                        src/pokemonism/window/cocoa/lib.hh
                                        src/pokemonism/window/cocoa/config.hh)

add_library(pokemonism-window-dev       ${POKEMONISM_WINDOW_SOURCE}
                                        ${POKEMONISM_WINDOW_HEADER})

