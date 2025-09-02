cmake_minimum_required(VERSION 3.28.3)

project(vileplume CXX)
set(CMAKE_CXX_STANDARD 23)

set(VILEPLUME_SOURCE                subscription.cc
                                    observable.cc)

set(VILEPLUME_HEADER                subscription.hh
                                    observable.hh)

add_library(vileplume-dev           ${VILEPLUME_HEADER}
                                    ${VILEPLUME_SOURCE})
