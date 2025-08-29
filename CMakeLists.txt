cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(include src pokemonism ./)

add_subdirectory(pokemonism/pokemon)
add_subdirectory(pokemonism/psyduck)
add_subdirectory(pokemonism/mareep)
add_subdirectory(pokemonism/latios)

set(POKEMONISM_ROOT_HEADER          include/pokemonism.hh)

set(POKEMONISM_ROOT_SOURCE          src/pokemonism.cc)

set(POKEMONISM_HEADER               src/primitivable.hh
        src/synchronizable.hh)

set(POKEMONISM_SOURCE               src/primitivable.cc
        src/synchronizable.cc)

set(POKEMONISM_IMPLEMENT_SOURCE     )

add_executable(pokemonism-dev       ${POKEMONISM_HEADER}
                                    ${POKEMONISM_SOURCE}
                                    ${POKEMONISM_ROOT_HEADER}
                                    ${POKEMONISM_ROOT_SOURCE}
                                    ${POKEMONISM_IMPLEMENT_SOURCE})

add_subdirectory(pokemonism/meowth/persian)