cmake_minimum_required(VERSION 3.28.3)

project(squirtle CXX)
set(CMAKE_CXX_STANDARD 23)

set(SQUIRTLE_ROOT_HEADER              ../squirtle.hh)

set(SQUIRTLE_ROOT_SOURCE              ../squirtle.cc)

set(SQUIRTLE_IMPLEMENT_SOURCE
        string.cc
        string.hh
        stream.cc
        stream.hh

)

add_library(pokemonism-squirtle       ${SQUIRTLE_ROOT_HEADER}
        ${SQUIRTLE_ROOT_SOURCE}
        ${SQUIRTLE_IMPLEMENT_SOURCE})
