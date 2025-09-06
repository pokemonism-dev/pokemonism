cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-pokemons-togepi LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_POKEMONS_TOGEPI_ROOT_HEADER      ../togepi.hh)

set(POKEMONISM_POKEMONS_TOGEPI_ROOT_SOURCE      ../togepi.cc)

set(POKEMONISM_POKEMONS_TOGEPI_HEADER           command.hh
                                                command/event.hh)

set(POKEMONISM_POKEMONS_TOGEPI_SOURCE           command.cc
                                                command/event.cc)

add_library(pokemonism-pokemons-togepi          ${POKEMONISM_POKEMONS_TOGEPI_ROOT_HEADER}
                                                ${POKEMONISM_POKEMONS_TOGEPI_ROOT_SOURCE}
                                                ${POKEMONISM_POKEMONS_TOGEPI_HEADER}
                                                ${POKEMONISM_POKEMONS_TOGEPI_SOURCE})