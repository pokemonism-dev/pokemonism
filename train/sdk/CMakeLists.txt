cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(train-pokemonism-sdk-engine                          train-pokemonism-sdk-engine.cc)
target_link_libraries(train-pokemonism-sdk-engine                   pokemonism-dev pokemonism-sdk)

add_executable(train-pokemonism-sdk-generic-command                 train-pokemonism-sdk-generic-command.cc)
target_link_libraries(train-pokemonism-sdk-generic-command          pokemonism-dev pokemonism-sdk)

add_executable(train-pokemonism-sdk-collection-continuous           train-pokemonism-sdk-collection-continuous.cc)
target_link_libraries(train-pokemonism-sdk-collection-continuous    pokemonism-dev pokemonism-sdk)

add_executable(train-pokemonism-sdk-buffer                          train-pokemonism-sdk-buffer.cc)
target_link_libraries(train-pokemonism-sdk-buffer                   pokemonism-dev pokemonism-sdk)

add_executable(train-pokemonism-sdk-typographer                     train-pokemonism-sdk-typographer.cc)
target_link_libraries(train-pokemonism-sdk-typographer              pokemonism-dev pokemonism-sdk)

add_executable(train-pokemonism-sdk-descriptor                      train-pokemonism-sdk-descriptor.cc)
target_link_libraries(train-pokemonism-sdk-descriptor               pokemonism-dev pokemonism-sdk)

add_executable(train-pokemonism-sdk-console                         train-pokemonism-sdk-console.cc)
target_link_libraries(train-pokemonism-sdk-console                  pokemonism-dev pokemonism-sdk)
