cmake_minimum_required(VERSION 3.28.3)

project(wattrel CXX)
set(CMAKE_CXX_STANDARD 23)

set(WATTREL_SOURCE                  engine.cc)

set(WATTREL_HEADER                  engine.hh)

add_library(wattrel-dev             ${WATTREL_HEADER}
                                    ${WATTREL_SOURCE})
