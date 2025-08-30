cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_HEADER                  object.hh
                                    message.hh
                                    envelope.hh
                                    exception.hh
                                    allocator.hh)

set(POKEMON_SOURCE                  object.cc
                                    message.cc
                                    envelope.cc
                                    exception.cc
                                    allocator.cc)

set(POKEMON_GENERAL_HEADER          general/message.hh
                                    general/command.hh
                                    general/envelope.hh
                                    general/functionable.hh)

set(POKEMON_GENERAL_SOURCE          general/message.cc
                                    general/command.cc
                                    general/envelope.cc
                                    general/functionable.cc)

add_library(pokemon-dev             ${POKEMON_HEADER}
                                    ${POKEMON_SOURCE}
                                    ${POKEMON_GENERAL_HEADER}
                                    ${POKEMON_GENERAL_SOURCE})
