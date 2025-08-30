cmake_minimum_required(VERSION 3.28.3)

project(sprigatito CXX)
set(CMAKE_CXX_STANDARD 23)

set(SPRIGATITO_SOURCE               collectable.cc)

set(SPRIGATITO_HEADER               collectable.hh)

add_library(sprigatito-dev          ${SPRIGATITO_SOURCE}
                                    ${SPRIGATITO_HEADER})
