cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-mathematics LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(src)

set(POKEMONISM_MATHEMATICS_SOURCE       src/pokemonism/mathematics.cc
                                        src/pokemonism/mathematics/scalar.cc
                                        src/pokemonism/mathematics/geometry.cc
                                        src/pokemonism/mathematics/geometry/rectangle.cc
                                        src/pokemonism/mathematics/linear/algebra/vector.cc
                                        src/pokemonism/mathematics/linear/algebra/vector/dimension/two.cc)

set(POKEMONISM_MATHEMATICS_HEADER       src/pokemonism/mathematics.hh
                                        src/pokemonism/mathematics/scalar.hh
                                        src/pokemonism/mathematics/geometry.hh
                                        src/pokemonism/mathematics/geometry/rectangle.hh
                                        src/pokemonism/mathematics/linear/algebra/vector.hh
                                        src/pokemonism/mathematics/linear/algebra/vector/dimension/two.hh)

add_library(pokemonism-mathematics      ${POKEMONISM_MATHEMATICS_SOURCE}
                                        ${POKEMONISM_MATHEMATICS_HEADER})

add_executable(pokemonism-mathematics-example-vector src/pokemonism/mathematics/linear/algebra/vector.cc)
target_link_libraries(pokemonism-mathematics-example-vector pokemonism-sdk)
target_compile_definitions(pokemonism-mathematics-example-vector PRIVATE __EXPOSE_POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_EXAMPLE)
