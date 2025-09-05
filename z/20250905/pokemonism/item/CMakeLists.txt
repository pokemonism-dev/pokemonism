cmake_minimum_required(VERSION 3.30)

project(pokemonism-item LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(ITEM_HEADER                         ../item.hh)

set(ITEM_SOURCE                         ../item.cc)

add_library(pokemonism-item-dev         ${ITEM_HEADER}
                                        ${ITEM_SOURCE})

