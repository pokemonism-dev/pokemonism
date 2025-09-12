cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-window LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_WINDOW_SOURCE            src/pokemonism/window.cc
                                        src/pokemonism/window/application.cc
                                        src/pokemonism/window/input/mouse.cc
                                        src/pokemonism/window/input/mouse/on.cc
                                        src/pokemonism/window/input/mouse/pos.cc
                                        src/pokemonism/window/input/keyboard.cc
                                        src/pokemonism/window/input/keyboard/on.cc
                                        src/pokemonism/window/input/keyboard/key.cc
                                        src/pokemonism/window/graphics/gammaramp.cc
                                        src/pokemonism/window/graphics/videomode.cc
                                        src/pokemonism/window/monitor.cc
                                        src/pokemonism/window/cursor.cc
                                        src/pokemonism/window/clipboard.cc
                                        src/pokemonism/window/platform.cc
                                        src/pokemonism/window/config.cc
                                        src/pokemonism/window/lib.cc
                                        src/pokemonism/window/vulkan/config.cc
                                        src/pokemonism/window/cocoa/lib.cc
                                        src/pokemonism/window/cocoa/cursor.cc
                                        src/pokemonism/window/cocoa/input/keyboard.cc
                                        src/pokemonism/window/cocoa/config.cc)

set(POKEMONISM_WINDOW_HEADER            src/pokemonism/window.hh
                                        src/pokemonism/window/application.hh
                                        src/pokemonism/window/input/mouse.hh
                                        src/pokemonism/window/input/mouse/on.hh
                                        src/pokemonism/window/input/mouse/pos.hh
                                        src/pokemonism/window/input/keyboard.hh
                                        src/pokemonism/window/input/keyboard/on.hh
                                        src/pokemonism/window/input/keyboard/key.hh
                                        src/pokemonism/window/graphics/gammaramp.hh
                                        src/pokemonism/window/graphics/videomode.hh
                                        src/pokemonism/window/monitor.hh
                                        src/pokemonism/window/cursor.hh
                                        src/pokemonism/window/clipboard.hh
                                        src/pokemonism/window/platform.hh
                                        src/pokemonism/window/config.hh
                                        src/pokemonism/window/lib.hh
                                        src/pokemonism/window/vulkan/config.hh
                                        src/pokemonism/window/cocoa/lib.hh
                                        src/pokemonism/window/cocoa/cursor.hh
                                        src/pokemonism/window/cocoa/input/keyboard.hh
                                        src/pokemonism/window/cocoa/config.hh)

add_library(pokemonism-window-dev       ${POKEMONISM_WINDOW_SOURCE}
                                        ${POKEMONISM_WINDOW_HEADER})

