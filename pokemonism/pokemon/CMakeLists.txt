cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_INTERFACE_SOURCE        interface/callable.hh
                                    interface/runnable.hh
                                    interface/functionable.hh
                                    interface/primitivable.hh
                                    interface/synchronizable.hh
                                    interface/terminatable.hh)

set(POKEMON_INTERFACE_HEADER        interface/callable.cc
                                    interface/runnable.cc
                                    interface/functionable.cc
                                    interface/primitivable.cc
                                    interface/synchronizable.cc
                                    interface/terminatable.cc)

set(POKEMON_GENERIC_SOURCE          generic/command.hh
                                    generic/envelope.hh
                                    generic/function.hh
                                    generic/lambda/callable.hh
                                    generic/lambda/command.hh
                                    generic/lambda/function.hh
                                    generic/lambda/runnable.hh)

set(POKEMON_GENERIC_HEADER          generic/command.cc
                                    generic/envelope.cc
                                    generic/function.cc
                                    generic/lambda/callable.cc
                                    generic/lambda/command.cc
                                    generic/lambda/function.cc
                                    generic/lambda/runnable.cc)

set(POKEMON_SOURCE                  allocator.cc
                                    event.cc
                                    object.cc
                                    command.cc
                                    message.cc
                                    envelope.cc
                                    exception.cc
                                    descriptor.cc
                                    runnable/queue.hh)

set(POKEMON_HEADER                  allocator.hh
                                    event.hh
                                    object.hh
                                    command.hh
                                    message.hh
                                    envelope.hh
                                    exception.hh
                                    descriptor.hh
                                    runnable/queue.cc)

add_library(pokemon-dev             ${POKEMON_INTERFACE_HEADER}
                                    ${POKEMON_INTERFACE_SOURCE}
                                    ${POKEMON_GENERIC_HEADER}
                                    ${POKEMON_GENERIC_SOURCE}
                                    ${POKEMON_HEADER}
                                    ${POKEMON_SOURCE})
