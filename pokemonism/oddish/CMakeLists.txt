cmake_minimum_required(VERSION 3.28.3)

project(oddish CXX)
set(CMAKE_CXX_STANDARD 23)

set(ODDISH_SOURCE                   subscription.cc
                                    observable.cc)

set(ODDISH_HEADER                   subscription.hh
                                    observable.hh)

add_library(oddish-dev              ${ODDISH_HEADER}
                                    ${ODDISH_SOURCE})

