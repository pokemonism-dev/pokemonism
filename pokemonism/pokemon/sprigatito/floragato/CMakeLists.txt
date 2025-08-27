cmake_minimum_required(VERSION 3.28.3)

project(floragato CXX)
set(CMAKE_CXX_STANDARD 23)

set(FLORAGATO_ROOT_HEADER              ../floragato.hh)

set(FLORAGATO_ROOT_SOURCE              ../floragato.cc)

set(FLORAGATO_IMPLEMENT_SOURCE
        collectable.cc
        collectable.hh
)

add_library(pokemonism-floragato       ${FLORAGATO_ROOT_HEADER}
        ${FLORAGATO_ROOT_SOURCE}
        ${FLORAGATO_IMPLEMENT_SOURCE})