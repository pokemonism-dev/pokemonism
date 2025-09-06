cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-tool LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./)

set(POKEMONISM_TOOL_HEADER              pokemonism/tool/randomizer.hh)

set(POKEMONISM_TOOL_SOURCE              pokemonism/tool/randomizer.cc)

add_library(pokemonism-tool-dev         ${POKEMONISM_TOOL_HEADER}
                                        ${POKEMONISM_TOOL_SOURCE})
