cmake_minimum_required(VERSION 3.30)

project(petilil LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(PETILIL_HEADER                          ../petilil.hh
                                            event.hh
                                            event/link.hh
                                            event/queue.hh
                                            event/envelope.hh
                                            event/generator.hh
                                            event/subscription.hh
                                            event/subscription/callback/set.hh
                                            event/modifiable/subscription.hh
                                            commandable/event.hh
                                            commandable/generator.hh
                                            commandable/processor.hh
                                            commandable/subscription.hh
                                            commandable/modifiable/subscription.hh)

set(PETILIL_SOURCE                          ../petilil.cc
                                            event.cc
                                            event/link.cc
                                            event/queue.cc
                                            event/envelope.cc
                                            event/generator.cc
                                            event/subscription.cc
                                            event/subscription/callback/set.cc
                                            event/modifiable/subscription.cc
                                            commandable/event.cc
                                            commandable/generator.cc
                                            commandable/processor.cc
                                            commandable/subscription.cc
                                            commandable/modifiable/subscription.cc)

add_library(petilil-dev                     ${PETILIL_HEADER}
                                            ${PETILIL_SOURCE})
