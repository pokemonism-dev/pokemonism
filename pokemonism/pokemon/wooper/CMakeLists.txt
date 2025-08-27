cmake_minimum_required(VERSION 3.28.3)

project(meowth CXX)
set(CMAKE_CXX_STANDARD 23)

set(WOOPER_ROOT_HEADER          ../wooper.hh)

set(WOOPER_ROOT_SOURCE          ../wooper.cc)

add_library(pokemonism-wooper   ${WOOPER_ROOT_HEADER}
                                ${WOOPER_ROOT_SOURCE})