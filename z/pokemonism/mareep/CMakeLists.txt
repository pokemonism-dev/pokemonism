cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(MAREEP_ROOT_HEADER              ../mareep.hh)

set(MAREEP_ROOT_SOURCE              ../mareep.cc)

set(MAREEP_HEADER                   subscription.hh
                                    observable.hh
                                    observer.hh)

set(MAREEP_SOURCE                   subscription.cc
                                    observable.cc
                                    observer.cc)

add_library(mareep-dev              ${MAREEP_ROOT_HEADER}
                                    ${MAREEP_ROOT_SOURCE}
                                    ${MAREEP_HEADER}
                                    ${MAREEP_SOURCE})
