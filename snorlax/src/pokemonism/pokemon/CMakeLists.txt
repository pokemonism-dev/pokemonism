cmake_minimum_required(VERSION 3.28.3)

project(pokemon CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMON_ROOT_HEADER                 ../pokemon.hh)

set(POKEMON_ROOT_SOURCE                 ../pokemon.cc)

set(POKEMON_HEADER                      typographer.hh
                                        allocator.hh
                                        object.hh
                                        function.hh
                                        exception.hh)

set(POKEMON_SOURCE                      typographer.cc
                                        allocator.cc
                                        object.cc
                                        function.cc
                                        exception.cc)

set(POKEMON_TEMPLATE_SOURCE             )

set(POKEMON_IMPLEMENT_SOURCE
        memorizer.cc
        memorizer.hh
        log.cc
        log.hh
        memorizer.template.unsigned.char.hh
        memorizer.template.unsigned.char.one.hh
        primitivable.hh
        primitivable.cc
)

add_library(pokemonism-dev              ${POKEMON_ROOT_HEADER}
                                        ${POKEMON_ROOT_SOURCE}
                                        ${POKEMON_SOURCE}
                                        ${POKEMON_HEADER}
                                        ${POKEMON_IMPLEMENT_SOURCE})
