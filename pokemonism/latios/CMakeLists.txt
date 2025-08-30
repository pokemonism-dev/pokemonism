cmake_minimum_required(VERSION 3.28.3)

project(latios CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_SOURCE              engine.cc)

set(POKEMON_HEADER              engine.hh)

add_library(latios-dev          ${POKEMON_HEADER}
                                ${POKEMON_SOURCE})
