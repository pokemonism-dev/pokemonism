cmake_minimum_required(VERSION 3.28.3)

project(bellossom CXX)
set(CMAKE_CXX_STANDARD 23)

set(BELLOSSOM_SOURCE                subscription.cc
                                    observable.cc)

set(BELLOSSOM_HEADER                subscription.hh
                                    observable.hh)

add_library(bellossom-dev           ${BELLOSSOM_HEADER}
                                    ${BELLOSSOM_SOURCE})
