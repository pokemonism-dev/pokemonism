cmake_minimum_required(VERSION 3.30)

project(pokemonism-pokemon-petilil LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./)

set(POKEMONISM_POKEMON_PETILIL_HEADER           ../petilil.hh)

set(POKEMONISM_POKEMON_PETILIL_SOURCE           ../petilil.cc)

add_library(pokemonism-pokemon-petilil-dev      ${POKEMONISM_POKEMON_PETILIL_HEADER}
                                                ${POKEMONISM_POKEMON_PETILIL_SOURCE})
