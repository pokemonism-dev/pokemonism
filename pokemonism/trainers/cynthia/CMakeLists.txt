cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-trainers-cynthia LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_TRAINERS_CYNTHIA_ROOT_HEADER     ../cynthia.hh)

set(POKEMONISM_TRAINERS_CYNTHIA_ROOT_SOURCE     ../cynthia.cc)

set(POKEMONISM_TRAINERS_CYNTHIA_HEADER          )

set(POKEMONISM_TRAINERS_CYNTHIA_SOURCE          )

add_library(pokemonism-trainers-cynthia         ${POKEMONISM_TRAINERS_CYNTHIA_ROOT_HEADER}
                                                ${POKEMONISM_TRAINERS_CYNTHIA_ROOT_SOURCE}
                                                ${POKEMONISM_TRAINERS_CYNTHIA_HEADER}
                                                ${POKEMONISM_TRAINERS_CYNTHIA_SOURCE})