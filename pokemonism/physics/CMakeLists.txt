cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-physics LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./src)

set(POKEMONISM_MATHEMATICS_SOURCE       src/pokemonism/mathematics.cc
                                        src/pokemonism/mathematics/scalar.cc
                                        src/pokemonism/mathematics/linear/algebra/vector.cc)

set(POKEMONISM_MATHEMATICS_HEADER       src/pokemonism/mathematics.hh
                                        src/pokemonism/mathematics/scalar.hh
                                        src/pokemonism/mathematics/linear/algebra/vector.hh)

set(POKEMONISM_PHYSICS_SOURCE           src/pokemonism/physics.cc
                                        src/pokemonism/physics/precision.cc
                                        src/pokemonism/physics/vector.cc
                                        src/pokemonism/physics/axis.cc
                                        src/pokemonism/physics/unit.cc
                                        src/pokemonism/physics/point.cc
                                        src/pokemonism/physics/dimensional.cc
                                        src/pokemonism/physics/coordinate.cc
                                        src/pokemonism/physics/coordinate/dimension/one.cc
                                        src/pokemonism/physics/coordinate/dimension/two.cc
                                        src/pokemonism/physics/mechanics.cc
                                        src/pokemonism/physics/mechanics/dynamics.cc
                                        src/pokemonism/physics/mechanics/kinematics.cc
                                        src/pokemonism/physics/mechanics/motion/translation.cc)

set(POKEMONISM_PHYSICS_HEADER           src/pokemonism/physics.hh
                                        src/pokemonism/physics/precision.hh
                                        src/pokemonism/physics/vector.hh
                                        src/pokemonism/physics/axis.hh
                                        src/pokemonism/physics/unit.hh
                                        src/pokemonism/physics/point.hh
                                        src/pokemonism/physics/dimensional.hh
                                        src/pokemonism/physics/coordinate.hh
                                        src/pokemonism/physics/coordinate/dimension/one.hh
                                        src/pokemonism/physics/coordinate/dimension/two.hh
                                        src/pokemonism/physics/mechanics.hh
                                        src/pokemonism/physics/mechanics/dynamics.hh
                                        src/pokemonism/physics/mechanics/kinematics.hh
                                        src/pokemonism/physics/mechanics/motion/translation.hh)

add_library(pokemonism-physics          ${POKEMONISM_MATHEMATICS_SOURCE}
                                        ${POKEMONISM_MATHEMATICS_HEADER}
                                        ${POKEMONISM_PHYSICS_SOURCE}
                                        ${POKEMONISM_PHYSICS_HEADER})
