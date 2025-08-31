cmake_minimum_required(VERSION 3.28.3)

project(latios CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_SOURCE               engine.cc
                                subscription.cc
                                command.cc
                                envelope.cc)

set(LATIOS_HEADER               engine.hh
                                subscription.hh
                                command.hh
                                envelope.hh)

add_library(latios-dev          ${LATIOS_HEADER}
                                ${LATIOS_SOURCE})
