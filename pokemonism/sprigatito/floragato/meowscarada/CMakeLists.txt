cmake_minimum_required(VERSION 3.28.3)

project(meowscarada CXX)
set(CMAKE_CXX_STANDARD 23)

set(MEOWSCARADA_SOURCE                  string.cc)

set(MEOWSCARADA_HEADER                  string.hh)

add_library(meowscarada-dev             ${MEOWSCARADA_SOURCE}
                                        ${MEOWSCARADA_HEADER})
