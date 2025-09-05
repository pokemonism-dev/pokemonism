cmake_minimum_required(VERSION 3.30)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_SDK_HEADER                   log.hh
                                            sync.hh
                                            event.hh
                                            event/link.hh
                                            event/queue.hh
                                            event/engine.hh
                                            event/envelope.hh
                                            event/generator.hh
                                            event/subscription.hh
                                            exception.hh
                                            generic/envelope.hh
                                            allocator.hh
                                            subscription.hh
                                            callable.hh
                                            runnable.hh
                                            cloneable.hh
                                            commandable.hh
                                            envelopeable.hh
                                            callbackable.hh
                                            primitivable.hh
                                            functionable.hh
                                            synchronizable.hh
                                            linked/list.hh
                                            )

set(POKEMONISM_SDK_SOURCE                   log.cc
                                            sync.cc
                                            event.cc
                                            event/link.cc
                                            event/queue.cc
                                            event/engine.cc
                                            event/envelope.cc
                                            event/generator.cc
                                            event/subscription.cc
                                            exception.cc
                                            generic/envelope.cc
                                            allocator.cc
                                            subscription.cc
                                            callable.cc
                                            runnable.cc
                                            cloneable.cc
                                            commandable.cc
                                            envelopeable.cc
                                            callbackable.cc
                                            primitivable.cc
                                            functionable.cc
                                            synchronizable.cc
                                            linked/list.cc)

add_library(pokemonism-sdk                  ${POKEMONISM_SDK_HEADER}
                                            ${POKEMONISM_SDK_SOURCE})
