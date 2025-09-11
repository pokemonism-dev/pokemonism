cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_SDK_SOURCE               application.cc)

set(POKEMONISM_SDK_HEADER               application.hh)

add_library(pokemonism-sdk              ${POKEMONISM_SDK_SOURCE}
                                        ${POKEMONISM_SDK_HEADER})
