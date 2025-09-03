cmake_minimum_required(VERSION 3.28.3)

project(gallade CXX)
set(CMAKE_CXX_STANDARD 23)

set(GALLADE_SOURCE                  subscription.cc)

set(GALLADE_HEADER                  subscription.hh)

add_library(gallade-dev             ${GALLADE_HEADER}
                                    ${GALLADE_SOURCE})
