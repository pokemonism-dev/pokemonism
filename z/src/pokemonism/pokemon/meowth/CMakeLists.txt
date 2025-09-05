cmake_minimum_required(VERSION 3.28.3)

project(meowth CXX)
set(CMAKE_CXX_STANDARD 23)

set(MEOWTH_ROOT_HEADER                      ../meowth.hh)

set(MEOWTH_ROOT_SOURCE                      ../meowth.cc)

add_library(pokemonism-meowth               ${MEOWTH_ROOT_HEADER}
                                            ${MEOWTH_ROOT_SOURCE})

add_executable(meowth-variant               variant.cc)
target_include_directories(meowth-variant   PRIVATE ../)

add_executable(meowth-sizeof-function       sizeof-function.cc)

add_executable(meowth-lamda-parameter       lamda-parameter.cc)

add_executable(meowth-virtual-return        virtual-return.cc)

add_executable(meowth-primitivable-object   primitivable-object.cc)
