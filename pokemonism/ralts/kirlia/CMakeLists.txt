cmake_minimum_required(VERSION 3.28.3)

project(kirlia CXX)
set(CMAKE_CXX_STANDARD 23)

set(KIRLIA_SOURCE               gardevoir.cc
                                gallade.cc
                                subscription.cc
                                observable.cc
                                engine.cc)

set(KIRLIA_HEADER               gardevoir.hh
                                gallade.hh
                                subscription.hh
                                observable.hh
                                engine.hh)

add_library(kirlia-dev          ${KIRLIA_HEADER}
                                ${KIRLIA_SOURCE})

add_subdirectory(gardevoir)
add_subdirectory(gallade)

