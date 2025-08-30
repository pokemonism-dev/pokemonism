cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_HEADER                   engine.hh)

set(LATIOS_SOURCE                   engine.cc)

set(LATIOS_INTERNAL_HEADER          internal/node.hh
                                    internal/event.hh
                                    internal/engine.hh
                                    internal/generator.hh
                                    internal/processor.hh
                                    internal/subscription.hh)

set(LATIOS_INTERNAL_SOURCE          internal/node.cc
                                    internal/event.cc
                                    internal/engine.cc
                                    internal/generator.cc
                                    internal/processor.cc
                                    internal/subscription.cc)

add_library(latios-dev              ${LATIOS_HEADER}
                                    ${LATIOS_SOURCE}
                                    ${LATIOS_INTERNAL_HEADER}
                                    ${LATIOS_INTERNAL_SOURCE})

target_link_libraries(latios-dev    pokemon-dev)
