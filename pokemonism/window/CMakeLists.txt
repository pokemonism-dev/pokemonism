cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-window LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(POKEMONISM_WINDOW_HEARER                                            src/pokemonism/window.cc
                                                                        src/pokemonism/interface/window.cc
                                                                        src/pokemonism/interface/window/config.cc
                                                                        src/pokemonism/interface/window/application.cc
                                                                        src/pokemonism/abstract/window.cc)

set(POKEMONISM_WINDOW_SOURCE                                            src/pokemonism/window.hh
                                                                        src/pokemonism/interface/window.hh
                                                                        src/pokemonism/interface/window/config.hh
                                                                        src/pokemonism/interface/window/application.hh
                                                                        src/pokemonism/abstract/window.hh)

add_library(pokemonism-window-dev                                       ${POKEMONISM_WINDOW_HEARER}
                                                                        ${POKEMONISM_WINDOW_SOURCE})


#
#set(POKEMONISM_WINDOW_COCOA_HEADER                                      src/pokemonism/window/platform/cocoa/application.hh
#                                                                        src/pokemonism/window/platform/cocoa/window.hh)
#
#set(POKEMONISM_WINDOW_COCOA_SOURCE                                      src/pokemonism/window/platform/cocoa/application.mm
#                                                                        src/pokemonism/window/platform/cocoa/window.mm)
#
#target_sources(pokemonism-window-dev                    PRIVATE         ${POKEMONISM_WINDOW_COCOA_HEADER}
#                                                                        ${POKEMONISM_WINDOW_COCOA_SOURCE})
#target_link_libraries(pokemonism-window-dev             PRIVATE         "-framework Cocoa"
#                                                                        "-framework IOKit"
#                                                                        "-framework CoreFoundation")
#
#add_executable(pokemonism-window-application                            src/pokemonism/window/application.cc)
#target_link_libraries(pokemonism-window-application         PRIVATE     "-framework Cocoa"
#                                                                        "-framework IOKit"
#                                                                        "-framework CoreFoundation"
#                                                                        pokemonism-window-dev
#                                                                        pokemonism-sdk
#                                                                        pokemonism-interface-dev)
#target_compile_definitions(pokemonism-window-application    PRIVATE     __EXPORT_POKEMONISM_WINDOW_APPLICATION_EXAMPLE)
#
#
#
##target_link_libraries(pokemonism-window-dev     PRIVATE     "-framework Cocoa"
##                                                            "-framework IOKit"
##                                                            "-framework CoreFoundation")
#
#
##target_sources(pokemonism-window-dev    PRIVATE ${POKEMONISM_WINDOW_COCOA_SOURCE}
##                                                ${POKEMONISM_WINDOW_COCOA_HEADER})
##
##set(POKEMONISM_WINDOW_SOURCE            src/pokemonism/window.cc
##                                        src/pokemonism/window/application.cc
##                                        src/pokemonism/window/interface/window.cc
##                                        src/pokemonism/window/interface/keyboard.cc
##                                        src/pokemonism/window/interface/keyboard/on.cc
##                                        src/pokemonism/window/interface/keyboard/key.cc
##                                        src/pokemonism/window/interface/mouse.cc
##                                        src/pokemonism/window/interface/mouse/on.cc
##                                        src/pokemonism/window/interface/mouse/pos.cc
##                                        src/pokemonism/window/interface/monitor.cc
##
##                                        src/pokemonism/window/input/mouse.cc
##                                        src/pokemonism/window/input/mouse/on.cc
##                                        src/pokemonism/window/input/mouse/pos.cc
##                                        src/pokemonism/window/input/keyboard.cc
##                                        src/pokemonism/window/input/keyboard/on.cc
##                                        src/pokemonism/window/input/keyboard/key.cc
##                                        src/pokemonism/window/graphics/gammaramp.cc
##                                        src/pokemonism/window/graphics/videomode.cc
##                                        src/pokemonism/window/monitor.cc
##                                        src/pokemonism/window/cursor.cc
##                                        src/pokemonism/window/clipboard.cc
##                                        src/pokemonism/window/platform.cc
##                                        src/pokemonism/window/config.cc
##                                        src/pokemonism/window/lib.cc
##                                        src/pokemonism/window/cfg.cc
##                                        src/pokemonism/window/vulkan/config.cc)
##
##set(POKEMONISM_WINDOW_HEADER            src/pokemonism/window.hh
##                                        src/pokemonism/window/application.hh
##                                        src/pokemonism/window/interface/window.hh
##                                        src/pokemonism/window/interface/keyboard.hh
##                                        src/pokemonism/window/interface/keyboard/on.hh
##                                        src/pokemonism/window/interface/keyboard/key.hh
##                                        src/pokemonism/window/interface/mouse.hh
##                                        src/pokemonism/window/interface/mouse/on.hh
##                                        src/pokemonism/window/interface/mouse/pos.hh
##                                        src/pokemonism/window/interface/monitor.hh
##
##                                        src/pokemonism/window/input/mouse.hh
##                                        src/pokemonism/window/input/mouse/on.hh
##                                        src/pokemonism/window/input/mouse/pos.hh
##                                        src/pokemonism/window/input/keyboard.hh
##                                        src/pokemonism/window/input/keyboard/on.hh
##                                        src/pokemonism/window/input/keyboard/key.hh
##                                        src/pokemonism/window/graphics/gammaramp.hh
##                                        src/pokemonism/window/graphics/videomode.hh
##                                        src/pokemonism/window/monitor.hh
##                                        src/pokemonism/window/cursor.hh
##                                        src/pokemonism/window/clipboard.hh
##                                        src/pokemonism/window/platform.hh
##                                        src/pokemonism/window/config.hh
##                                        src/pokemonism/window/cfg.hh
##                                        src/pokemonism/window/lib.hh
##                                        src/pokemonism/window/vulkan/config.hh)
##
##
###                                        src/pokemonism/window/cocoa/window.hh
###                                        src/pokemonism/window/cocoa/lib.hh
###                                        src/pokemonism/window/cocoa/cursor.hh
###                                        src/pokemonism/window/cocoa/input/keyboard.hh
###                                        src/pokemonism/window/cocoa/input/mouse.hh
###                                        src/pokemonism/window/cocoa/config.hh)
##
##set(POKEMONISM_WINDOW_COCOA_SOURCE      src/pokemonism/window/cocoa/window.mm
##                                        src/pokemonism/window/cocoa/mouse.mm
##                                        src/pokemonism/window/cocoa/monitor.mm
##                                        src/pokemonism/window/cocoa/keyboard.mm)
##
##set(POKEMONISM_WINDOW_COCOA_HEADER      src/pokemonism/window/cocoa/window.hh
##                                        src/pokemonism/window/cocoa/mouse.hh
##                                        src/pokemonism/window/cocoa/monitor.hh
##                                        src/pokemonism/window/cocoa/keyboard.hh)
##
##add_library(pokemonism-window-dev       ${POKEMONISM_WINDOW_SOURCE}
##        ${POKEMONISM_WINDOW_HEADER})
##
##target_sources(pokemonism-window-dev    PRIVATE ${POKEMONISM_WINDOW_COCOA_SOURCE}
##                                                ${POKEMONISM_WINDOW_COCOA_HEADER})
##
##target_link_libraries(pokemonism-window-dev     PRIVATE     "-framework Cocoa"
##                                                            "-framework IOKit"
##                                                            "-framework CoreFoundation")
##
###add_executable(pokemonism-window-example src/pokemonism/window.cc)
###target_compile_definitions(pokemonism-window-example PRIVATE __EXPORT_POKEMONISM_WINDOW_EXAMPLE)
###target_link_libraries(pokemonism-window-example PRIVATE     "-framework Cocoa"
###                                                            "-framework IOKit"
###                                                            "-framework CoreFoundation"
###                                                            pokemonism-window-dev
###                                                            pokemonism-sdk)
##
##add_executable(pokemonism-window-application-example                            src/pokemonism/window.cc)
##target_compile_definitions(pokemonism-window-application-example    PRIVATE     __EXPORT_POKEMONISM_WINDOW_APPLICATION_EXAMPLE)
##target_link_libraries(pokemonism-window-application-example         PRIVATE     "-framework Cocoa"
##                                                                                "-framework IOKit"
##                                                                                "-framework CoreFoundation"
##                                                                                pokemonism-window-dev
##                                                                                pokemonism-sdk)
