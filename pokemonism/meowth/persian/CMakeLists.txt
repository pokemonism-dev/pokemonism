cmake_minimum_required(VERSION 3.28.3)

project(persian CXX)
set(CMAKE_CXX_STANDARD 23)

set(PERSIAN_ROOT_SOURCE                                 ../persian.cc)

set(PERSIAN_ROOT_HEADER                                 ../persian.hh)

add_library(persian-dev                                 ${PERSIAN_ROOT_SOURCE}
                                                        ${PERSIAN_ROOT_HEADER})

add_executable(persian-pokemon-terminator               persian-pokemon-terminator.cc)

add_executable(persian-kirlia-engine-command            persian-kirlia-engine-command.cc)
target_link_libraries(persian-kirlia-engine-command     gardevoir-dev kirlia-dev ralts-dev persian-dev)

