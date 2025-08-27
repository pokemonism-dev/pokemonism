cmake_minimum_required(VERSION 3.28.3)

project(persian CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(persian-sprigatito-string            sprigatito-string.cc)
target_link_libraries(persian-sprigatito-string     pokemonism-sprigatito)

add_executable(persian-sprigatito-stream            sprigatito-stream.cc)
target_link_libraries(persian-sprigatito-stream     pokemonism-sprigatito)

add_executable(persian-latios-engine                latios-engine.cc)
target_link_libraries(persian-latios-engine         pokemonism-latio
                                                    pokemonism-sprigatito
                                                    pokemonism-dev)
