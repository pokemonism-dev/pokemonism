cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(PSYDUCK_ROOT_HEADER                 ../psyduck.hh)

set(PSYDUCK_ROOT_SOURCE                 ../psyduck.cc)

set(PSYDUCK_HEADER                      linked/list.hh)

set(PSYDUCK_SOURCE                      linked/list.hh)

add_library(psyduck-dev                 ${PSYDUCK_ROOT_HEADER}
                                        ${PSYDUCK_ROOT_SOURCE}
                                        ${PSYDUCK_HEADER}
                                        ${PSYDUCK_SOURCE})
