cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_ROOT_HEADER                  ../latios.hh)

set(LATIOS_ROOT_SOURCE                  ../latios.hh)

set(LATIOS_HEADER                       event.cc)

set(LATIOS_SOURCE                       event.cc)

set(LATIOS_INTERNAL_HEADER              internal.hh
                                        internal/linked/list.hh
                                        internal/event.hh
                                        internal/generator.hh
                                        internal/subscription.hh)

set(LATIOS_INTERNAL_SOURCE              internal.cc
                                        internal/linked/list.cc
                                        internal/event.cc
                                        internal/generator.cc
                                        internal/subscription.cc)

set(LATIOS_IMPLEMENT_SOURCE
        object.cc
        object.hh
        subscription.cc
        subscription.hh
        linked.cc
        linked.hh
        linked/list.cc
        linked/list.hh
        engine.cc
        engine.hh
        command.cc
        command.hh
        command/object.cc
        command/object.hh)

add_library(pokemonism-latio-dev        ${LATIOS_INTERNAL_HEADER}
                                        ${LATIOS_INTERNAL_SOURCE})

add_library(pokemonism-latio            ${LATIOS_ROOT_HEADER}
                                        ${LATIOS_ROOT_SOURCE}
                                        ${LATIOS_HEADER}
                                        ${LATIOS_SOURCE}
                                        ${LATIOS_IMPLEMENT_SOURCE})
target_link_libraries(pokemonism-latio  pokemonism-latio-dev
                                        pokemonism-dev)