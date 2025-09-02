cmake_minimum_required(VERSION 3.28.3)

project(gardevoir CXX)
set(CMAKE_CXX_STANDARD 23)

set(GARDEVOIR_SOURCE                subscription.cc
                                    observable.cc)

set(GARDEVOIR_HEADER                subscription.hh
                                    observable.hh)

add_library(gardevoir-dev           ${GARDEVOIR_HEADER}
                                    ${GARDEVOIR_SOURCE})
