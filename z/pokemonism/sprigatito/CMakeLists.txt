cmake_minimum_required(VERSION 3.28.3)

project(sprigatito CXX)
set(CMAKE_CXX_STANDARD 23)

set(SPRIGATITO_HEADER                   tuple/pair.hh)

set(SPRIGATITO_SOURCE                   tuple/pair.cc)

add_library(sprigatito-dev              ${SPRIGATITO_HEADER}
                                        ${SPRIGATITO_SOURCE})