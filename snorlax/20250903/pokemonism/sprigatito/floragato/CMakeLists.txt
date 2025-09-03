cmake_minimum_required(VERSION 3.28.3)

project(floragato CXX)
set(CMAKE_CXX_STANDARD 23)

set(FLORAGATO_SOURCE                stream.cc
                                    string.cc)

set(FLORAGATO_HEADER                stream.hh
                                    string.hh)

add_library(floragato-dev           ${FLORAGATO_SOURCE}
                                    ${FLORAGATO_HEADER})

add_subdirectory(meowscarada)