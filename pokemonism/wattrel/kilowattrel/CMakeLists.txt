cmake_minimum_required(VERSION 3.28.3)

project(kilowattrel CXX)
set(CMAKE_CXX_STANDARD 23)

set(KILOWATTREL_SOURCE                  subscription.cc)

set(KILOWATTREL_HEADER                  subscription.hh)

add_library(kilowattrel-dev             ${KILOWATTREL_HEADER}
                                        ${KILOWATTREL_SOURCE})
