cmake_minimum_required(VERSION 3.28.3)

project(ralts CXX)
set(CMAKE_CXX_STANDARD 23)

set(RALTS_SOURCE                kirlia.cc
                                subscription.cc
                                observable.cc)

set(RALTS_HEADER                kirlia.hh
                                subscription.hh
                                observable.hh)

add_library(ralts-dev           ${RALTS_HEADER}
                                ${RALTS_SOURCE})

add_subdirectory(kirlia)
