cmake_minimum_required(VERSION 3.28.3)

project(mareep CXX)
set(CMAKE_CXX_STANDARD 23)

set(MAREEP_SOURCE               subscription.cc
                                observable.cc)

set(MAREEP_HEADER               subscription.hh
                                observable.hh)

add_library(mareep-dev          ${MAREEP_HEADER}
                                ${MAREEP_SOURCE})
