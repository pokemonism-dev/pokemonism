cmake_minimum_required(VERSION 3.28.3)

project(petilil CXX)
set(CMAKE_CXX_STANDARD 23)

set(PETILIL_SOURCE                  subscription.cc)

set(PETILIL_HEADER                  subscription.hh)

add_library(petilil-dev             ${PETILIL_SOURCE}
                                    ${PETILIL_HEADER})
