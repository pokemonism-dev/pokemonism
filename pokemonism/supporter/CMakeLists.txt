cmake_minimum_required(VERSION 3.30)

project(pokemonism-supporter LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(SUPPORTER_HEADER                        ../supporter.hh
                                            lana.hh)

set(SUPPORTER_SOURCE                        ../supporter.cc
                                            lana.cc)

add_library(pokemonism-supporter-dev        ${SUPPORTER_HEADER}
                                            ${SUPPORTER_SOURCE})

