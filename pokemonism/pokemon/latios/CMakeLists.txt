cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_ROOT_HEADER                  ../latios.hh)

set(LATIOS_ROOT_SOURCE                  ../latios.hh)

set(LATIOS_HEADER                       event.cc)

set(LATIOS_SOURCE                       event.cc)

set(LATIOS_IMPLEMENT_SOURCE
    linked.cc
        linked.hh
        linked/list.cc
        linked/list.hh
        queue.cc
        queue.hh
        engine.cc
        engine.hh)

add_library(pokemonism-latio            ${LATIOS_ROOT_HEADER}
                                        ${LATIOS_ROOT_SOURCE}
                                        ${LATIOS_HEADER}
                                        ${LATIOS_SOURCE}
                                        ${LATIOS_IMPLEMENT_SOURCE})
target_link_libraries(pokemonism-latio  pokemonism-dev)