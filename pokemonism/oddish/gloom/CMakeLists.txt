cmake_minimum_required(VERSION 3.28.3)

project(gloom CXX)
set(CMAKE_CXX_STANDARD 23)

set(GLOOM_SOURCE                    subscription.cc
                                    observable.cc)

set(GLOOM_HEADER                    subscription.hh
                                    observable.hh)

add_library(gloom-dev               ${GLOOM_HEADER}
                                    ${GLOOM_SOURCE})
