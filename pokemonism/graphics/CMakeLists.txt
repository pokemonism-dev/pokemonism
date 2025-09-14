cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-graphics LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(POKEMONISM_GRAPHICS_SOURCE          src/pokemonism/graphics.cc
                                        src/pokemonism/graphics/color.cc)

set(POKEMONISM_GRAPHICS_HEADER          src/pokemonism/graphics.hh
                                        src/pokemonism/graphics/color.hh)

add_library(pokemonism-graphics         ${POKEMONISM_GRAPHICS_SOURCE}
                                        ${POKEMONISM_GRAPHICS_HEADER})
