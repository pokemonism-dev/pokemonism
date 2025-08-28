cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_HEADER                   ../latios.hh
                                    engine.hh)

set(LATIOS_SOURCE                   ../latios.cc
                                    engine.cc)

set(LATIOS_EXTERNAL_HEADER          external/engine.hh)

set(LATIOS_EXTERNAL_SOURCE          external/engine.cc)

set(LATIOS_INTERNAL_HEADER          internal/engine.hh)

set(LATIOS_INTERNAL_SOURCE          internal/engine.cc)

add_library(latios-dev              ${LATIOS_HEADER}
                                    ${LATIOS_SOURCE}
                                    ${LATIOS_EXTERNAL_HEADER}
                                    ${LATIOS_EXTERNAL_SOURCE}
                                    ${LATIOS_INTERNAL_HEADER}
                                    ${LATIOS_INTERNAL_SOURCE})

target_link_libraries(latios-dev    pokemon-dev)
