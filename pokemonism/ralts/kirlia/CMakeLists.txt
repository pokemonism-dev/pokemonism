cmake_minimum_required(VERSION 3.28.3)

project(kirlia CXX)
set(CMAKE_CXX_STANDARD 23)

set(KIRLIA_SOURCE               gardevoir.cc
                                gallade.cc
                                subscription.cc
                                observable.cc
                                event.cc
                                engine.cc
                                envelope.cc
                                command.cc)

set(KIRLIA_HEADER               gardevoir.hh
                                gallade.hh
                                subscription.hh
                                observable.hh
                                event.hh
                                engine.hh
                                envelope.hh
                                command.hh)

add_library(kirlia-dev          ${KIRLIA_HEADER}
                                ${KIRLIA_SOURCE})

add_subdirectory(gardevoir)
add_subdirectory(gallade)

