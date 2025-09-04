cmake_minimum_required(VERSION 3.30)

project(petilil LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(PETILIL_HEADER                          ../petilil.hh)

set(PETILIL_SOURCE                          ../petilil.cc)

add_library(petilil-dev                     ${PETILIL_HEADER}
                                            ${PETILIL_SOURCE})
