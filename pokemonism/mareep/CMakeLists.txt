cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(MAREEP_HEADER                   ../mareep.hh
                                    subscription.hh)

set(MAREEP_SOURCE                   ../mareep.cc
                                    subscription.cc)

add_library(mareep-dev              ${MAREEP_HEADER}
                                    ${MAREEP_SOURCE})
