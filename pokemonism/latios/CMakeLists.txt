cmake_minimum_required(VERSION 3.28.3)

project(latios CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_SOURCE               subscription.cc)

set(LATIOS_HEADER               subscription.hh)

add_library(latios-dev          ${LATIOS_HEADER}
                                ${LATIOS_SOURCE})
