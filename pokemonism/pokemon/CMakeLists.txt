cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_INTERFACE_SOURCE        interface/commandable.hh
                                    interface/functionable.hh
                                    interface/primitivable.hh
                                    interface/synchronizable.hh
                                    interface/throwable.hh)

set(POKEMON_INTERFACE_HEADER        interface/commandable.cc
                                    interface/functionable.cc
                                    interface/primitivable.cc
                                    interface/synchronizable.cc
                                    interface/throwable.cc)

set(POKEMON_SOURCE                  object.cc
                                    command.cc
                                    message.cc
                                    envelope.cc
                                    exception.cc
                                    descriptor.cc)

set(POKEMON_HEADER                  object.hh
                                    command.hh
                                    message.hh
                                    envelope.hh
                                    exception.hh
                                    descriptor.hh)

add_library(pokemon-dev             ${POKEMON_INTERFACE_HEADER}
                                    ${POKEMON_INTERFACE_SOURCE}
                                    ${POKEMON_HEADER}
                                    ${POKEMON_SOURCE})
