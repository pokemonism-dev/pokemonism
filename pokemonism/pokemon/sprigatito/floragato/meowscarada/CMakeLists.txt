cmake_minimum_required(VERSION 3.28.3)

project(meowscarada CXX)
set(CMAKE_CXX_STANDARD 23)

set(MEOWSCARADA_ROOT_HEADER              ../meowscarada.hh)

set(MEOWSCARADA_ROOT_SOURCE              ../meowscarada.cc)

set(MEOWSCARADA_IMPLEMENT_SOURCE
        collectable.cc
        collectable.hh
)

add_library(pokemonism-meowscarada       ${MEOWSCARADA_ROOT_HEADER}
        ${MEOWSCARADA_ROOT_SOURCE}
        ${MEOWSCARADA_IMPLEMENT_SOURCE})