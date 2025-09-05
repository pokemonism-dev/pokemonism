cmake_minimum_required(VERSION 3.30)

project(pokemonism-stadium LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(STADIUM_HEADER                          ../stadium.hh)

set(STADIUM_SOURCE                          ../stadium.cc)

add_library(pokemonism-stadium-dev          ${STADIUM_HEADER}
                                            ${STADIUM_SOURCE})

