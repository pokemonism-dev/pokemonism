cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-vulkan LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_VULKAN_SOURCE            src/pokemonism/vulkan.cc
                                        src/pokemonism/vulkan/window.cc
                                        src/pokemonism/vulkan/application.cc)

set(POKEMONISM_VULKAN_HEADER            src/pokemonism/vulkan.hh
                                        src/pokemonism/vulkan/window.hh
                                        src/pokemonism/vulkan/application.hh)

add_library(pokemonism-vulkan-dev       ${POKEMONISM_VULKAN_SOURCE}
                                        ${POKEMONISM_VULKAN_HEADER})
