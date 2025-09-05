cmake_minimum_required(VERSION 3.28.3)

project(psyduck CXX)
set(CMAKE_CXX_STANDARD 23)

set(PSYDUCK_SOURCE              linked/list.cc)

set(PSYDUCK_HEADER              linked/list.hh)

add_library(psyduck-dev         ${PSYDUCK_HEADER}
                                ${PSYDUCK_SOURCE})
