cmake_minimum_required(VERSION 3.30)

project(squirtle LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(SQUIRTLE_HEADER                         ../psyduck.hh
                                            linked/list.hh)

set(SQUIRTLE_SOURCE                         ../psyduck.cc)

add_library(squirtle-dev                    ${SQUIRTLE_HEADER}
                                            ${SQUIRTLE_SOURCE})
