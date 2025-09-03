cmake_minimum_required(VERSION 3.28.3)

project(petilil-dev CXX)

set(CMAKE_CXX_STANDARD 23)

set(PETILIL_ROOT_HEADER                     ../petilil.hh)

set(PETILIL_ROOT_SOURCE                     ../petilil.cc)

set(PETILIL_HEADER                          event.hh
                                            command.hh)

set(POKEMON_SOURCE                          event.cc
                                            command.cc)

add_library(petilil-dev                     ${PETILIL_ROOT_HEADER}
                                            ${PETILIL_ROOT_SOURCE}
                                            ${PETILIL_HEADER}
                                            ${PETILIL_SOURCE})

