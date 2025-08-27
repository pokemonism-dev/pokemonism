cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_ROOT_HEADER                  ../latios.hh)

set(LATIOS_ROOT_SOURCE                  ../latios.cc)

set(LATIOS_HEADER                       event.cc)

set(LATIOS_SOURCE                       event.cc)

set(LATIOS_INTERNAL_HEADER              internal.hh
                                        internal/linked/list.hh
                                        internal/linked.hh
                                        internal/pure/event.hh
                                        internal/queue.hh
                                        internal/event.hh
                                        internal/link.hh
                                        internal/generator.hh
                                        internal/subscription.hh
                                        )

set(LATIOS_INTERNAL_SOURCE              internal.cc
                                        internal/linked/list.cc
                                        internal/linked.cc
                                        internal/pure/event.cc
                                        internal/queue.cc
                                        internal/event.cc
                                        internal/link.cc
                                        internal/generator.cc
                                        internal/subscription.cc
                                        )

set(LATIOS_IMPLEMENT_SOURCE

        internal/generator.cc

        internal/command.cc
        internal/command/event.cc
        internal/command/subscription.cc

        internal/queue.hh

        internal/subscription.hh
        internal/command.hh
        internal/command/event.hh
        internal/command/subscription.hh

        internal/engine.cc
        internal/engine.hh
        internal/linked.cc
        internal/linked.hh
        object.cc
        object.hh
        subscription.cc
        subscription.hh
        external/engine.cc
        external/engine.hh
        external/command.cc
        external/command.hh
        external/command/event.cc
        external/command/event.hh
        handler.cc
        handler.hh
        command.cc
        command.hh)

add_library(pokemonism-latio-dev        ${LATIOS_INTERNAL_HEADER}
                                        ${LATIOS_INTERNAL_SOURCE})

add_library(pokemonism-latio            ${LATIOS_ROOT_HEADER}
                                        ${LATIOS_ROOT_SOURCE}
                                        ${LATIOS_HEADER}
                                        ${LATIOS_SOURCE})

target_link_libraries(pokemonism-latio  pokemonism-latio-dev
                                        pokemonism-dev)