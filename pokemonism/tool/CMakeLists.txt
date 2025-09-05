cmake_minimum_required(VERSION 3.30)

project(pokemonism-tool LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(TOOL_HEADER                         ../tool.hh)

set(TOOL_SOURCE                         ../tool.cc)

add_library(pokemonism-tool-dev         ${TOOL_HEADER}
                                        ${TOOL_SOURCE})

