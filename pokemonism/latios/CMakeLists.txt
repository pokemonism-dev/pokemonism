cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_ROOT_HEADER              ../latios.hh)

set(LATIOS_ROOT_SOURCE              ../latios.cc)

set(LATIOS_HEADER                   engine.hh
                                    event.hh
                                    command.hh)

set(LATIOS_SOURCE                   engine.cc
                                    event.cc
                                    command.cc)

set(LATIOS_EXTERNAL_HEADER          external/engine.hh)

set(LATIOS_EXTERNAL_SOURCE          external/engine.cc)

set(LATIOS_INTERNAL_HEADER          internal/event.hh
                                    internal/queue.hh
                                    internal/engine.hh
                                    internal/generator.hh
                                    internal/subscription.hh
                                    internal/command/event.hh)

set(LATIOS_INTERNAL_SOURCE          internal/event.cc
                                    internal/queue.cc
                                    internal/engine.cc
                                    internal/generator.cc
                                    internal/subscription.cc
                                    internal/command/event.cc)

add_library(latios-dev              ${LATIOS_ROOT_HEADER}
                                    ${LATIOS_ROOT_SOURCE}
                                    ${LATIOS_HEADER}
                                    ${LATIOS_SOURCE}
                                    ${LATIOS_EXTERNAL_HEADER}
                                    ${LATIOS_EXTERNAL_SOURCE}
                                    ${LATIOS_INTERNAL_HEADER}
                                    ${LATIOS_INTERNAL_SOURCE})

target_link_libraries(latios-dev    pokemon-dev)
