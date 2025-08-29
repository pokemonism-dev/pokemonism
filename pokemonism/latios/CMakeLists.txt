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

set(LATIOS_EXTERNAL_HEADER          external/event.hh
                                    external/engine.hh
                                    external/subscription.hh)

set(LATIOS_EXTERNAL_SOURCE          external/event.cc
                                    external/engine.cc
                                    external/subscription.cc)

set(LATIOS_GENERAL_HEADER           general/event.hh
                                    general/queue.hh
                                    general/engine.hh
                                    general/processor.hh
                                    general/generator.hh
                                    general/subscription.hh)

set(LATIOS_GENERAL_SOURCE           general/event.cc
                                    general/queue.cc
                                    general/engine.cc
                                    general/processor.cc
                                    general/generator.cc
                                    general/subscription.cc)

set(LATIOS_INTERNAL_HEADER          internal/observable.hh
                                    internal/event.hh)

set(LATIOS_INTERNAL_SOURCE          internal/observable.cc
                                    internal/event.cc)

add_library(latios-dev              ${LATIOS_ROOT_HEADER}
                                    ${LATIOS_ROOT_SOURCE}
                                    ${LATIOS_HEADER}
                                    ${LATIOS_SOURCE}
                                    ${LATIOS_EXTERNAL_HEADER}
                                    ${LATIOS_EXTERNAL_SOURCE}
                                    ${LATIOS_GENERAL_HEADER}
                                    ${LATIOS_GENERAL_SOURCE}
                                    ${LATIOS_INTERNAL_HEADER}
                                    ${LATIOS_INTERNAL_SOURCE})

target_link_libraries(latios-dev    pokemon-dev)
