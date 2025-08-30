cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_SOURCE              command.cc
                                descriptor.cc)

set(POKEMON_HEADER              command.hh
                                descriptor.hh)

add_library(pokemon-dev         ${POKEMON_HEADER}
                                ${POKEMON_SOURCE})
