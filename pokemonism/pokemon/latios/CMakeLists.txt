cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_ROOT_HEADER                  ../latios.hh)

set(LATIOS_ROOT_SOURCE                  ../latios.cc)

set(LATIOS_HEADER                       event.hh
                                        object.hh
                                        engine.hh
                                        exception.hh
                                        subscription.hh
                                        command.hh
                                        external/command/event.hh
                                        external/command/subscription.hh)

set(LATIOS_SOURCE                       event.cc
                                        object.cc
                                        engine.cc
                                        exception.cc
                                        subscription.cc
                                        command.cc
                                        external/command/event.cc
                                        external/command/subscription.cc)


set(LATIOS_INTERNAL_HEADER              internal.hh
                                        internal/linked/list.hh
                                        internal/linked.hh
                                        external/engine.hh
                                        internal/queue.hh
                                        internal/event.hh
                                        internal/engine.hh
                                        internal/generator.hh
                                        internal/processor.hh
                                        internal/subscription.hh
                                        internal/command/event.hh
                                        internal/command/generator.hh
                                        internal/command/processor.hh
                                        internal/command/subscription.hh
                                        internal/command/subscription/repeat.hh)

set(LATIOS_INTERNAL_SOURCE              internal.cc
                                        internal/linked/list.cc
                                        internal/linked.cc
                                        external/engine.cc
                                        internal/queue.cc
                                        internal/event.cc
                                        internal/engine.cc
                                        internal/generator.cc
                                        internal/processor.cc
                                        internal/subscription.cc
                                        internal/command/event.cc
                                        internal/command/generator.cc
                                        internal/command/processor.cc
                                        internal/command/subscription.cc
                                        internal/command/subscription/repeat.cc)

set(LATIOS_IMPLEMENT_SOURCE             )

add_library(pokemonism-latio-dev        ${LATIOS_INTERNAL_HEADER}
                                        ${LATIOS_INTERNAL_SOURCE})

add_library(pokemonism-latio            ${LATIOS_ROOT_HEADER}
                                        ${LATIOS_ROOT_SOURCE}
                                        ${LATIOS_HEADER}
                                        ${LATIOS_SOURCE}
                                        ${LATIOS_IMPLEMENT_SOURCE})

target_link_libraries(pokemonism-latio  pokemonism-latio-dev
                                        pokemonism-dev)