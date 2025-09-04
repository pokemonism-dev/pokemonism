cmake_minimum_required(VERSION 3.30)

project(train LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(train-petilil            train-petilil.cc)
target_link_libraries(train-petilil     pokemon-dev petilil-dev)