cmake_minimum_required(VERSION 3.30)

project(pokemonism-supporter LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(SUPPORTER_HEADER                        ../supporter.hh)

set(SUPPORTER_SOURCE                        ../supporter.cc)

add_library(pokemonism-supporter-dev        ${SUPPORTER_HEADER}
                                            ${SUPPORTER_SOURCE})

