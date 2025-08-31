cmake_minimum_required(VERSION 3.28.3)

project(wattrel CXX)
set(CMAKE_CXX_STANDARD 23)

set(WATTREL_SOURCE                  node.cc
                                    event.cc
                                    queue.cc
                                    engine.cc
                                    command.cc
                                    generator.cc
                                    subscription.cc)

set(WATTREL_HEADER                  node.cc
                                    event.hh
                                    queue.hh
                                    engine.hh
                                    command.hh
                                    generator.hh
                                    subscription.hh)

add_library(wattrel-dev             ${WATTREL_HEADER}
                                    ${WATTREL_SOURCE})
