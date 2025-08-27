cmake_minimum_required(VERSION 3.28.3)

project(persian CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(pokemonism-pokemon-persian-future persian-future.cpp)
target_link_libraries(pokemonism-pokemon-persian-future pokemonism-dev)

add_executable(pokemonism-pokemon-persian-promise persian-promise.cpp)
target_link_libraries(pokemonism-pokemon-persian-promise pokemonism-dev)

add_executable(pokemonism-pokemon-persian-future-impl persian-future-impl.cpp)
target_link_libraries(pokemonism-pokemon-persian-future-impl pokemonism-dev)

add_executable(pokemonism-pokemon-persian-return-performance persian-return-performance.cpp)
target_compile_options(pokemonism-pokemon-persian-return-performance PRIVATE -O3)

add_executable(pokemonism-pokemon-persian-this-delete persian-this-delete.cpp)
target_compile_options(pokemonism-pokemon-persian-this-delete PRIVATE -O3)

add_executable(pokemonism-pokemon-persian-reference-impl persian-reference-impl.cpp)
target_link_libraries(pokemonism-pokemon-persian-reference-impl pokemonism-dev)

add_executable(pokemonism-pokemon-persian-variable-impl persian-variable-impl.cpp)
target_link_libraries(pokemonism-pokemon-persian-variable-impl pokemonism-dev)

add_executable(pokemonism-pokemon-persian-variance-impl persian-variance-impl.cpp)
target_link_libraries(pokemonism-pokemon-persian-variance-impl pokemonism-dev)

