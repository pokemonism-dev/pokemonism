cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_SOURCE                      )

set(POKEMON_HEADER                      )

set(POKEMON_IMPLEMENT_SOURCE
        typographer.cc
        typographer.hh
        sprigatito.cc
        sprigatito.hh
        sprigatito/wide/string.cc
        sprigatito/wide/string.hh
        functionable.cc
        functionable.hh
        memorizer.cc
        memorizer.hh
        allocator.cc
        allocator.hh
        throwable.cc
        throwable.hh
        exception.cc
        exception.hh
        exception.tcc
        log.cc
        log.hh
        allocator.tcc
        allocator.void.tcc
        promise.cc
        promise.hh
        future.cc
        future.hh
        object.cc
        object.hh
        objectable.cc
        objectable.hh
        dynamical.cc
        dynamical.hh
        reference.cc
        reference.hh
        pointable.cc
        pointable.hh)

add_library(pokemonism-dev                      ${POKEMON_SOURCE}
                                        ${POKEMON_HEADER}
                                        ${POKEMON_IMPLEMENT_SOURCE})
