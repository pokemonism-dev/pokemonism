cmake_minimum_required(VERSION 3.28.3)

project(mareep CXX)
set(CMAKE_CXX_STANDARD 23)

set(MAREEP_ROOT_HEADER              ../mareep.hh)

set(MAREEP_ROOT_SOURCE              ../mareep.cc)

set(MAREEP_IMPLEMENT_SOURCE
        observable.cc
        observable.hh
        subscription.cc
        subscription.hh
)

add_library(pokemonism-mareep       ${MAREEP_ROOT_HEADER}
        ${MAREEP_ROOT_SOURCE}
        ${MAREEP_IMPLEMENT_SOURCE})
