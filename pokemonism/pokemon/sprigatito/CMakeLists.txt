cmake_minimum_required(VERSION 3.28.3)

project(sprigatito CXX)
set(CMAKE_CXX_STANDARD 23)

set(SPRIGATITO_ROOT_HEADER              ../sprigatito.hh)

set(SPRIGATITO_ROOT_SOURCE              ../sprigatito.cc)

set(SPRIGATITO_INTERFACE_HEADER         iterable.hh
                                        collectable.hh
                                        scannable.hh
                                        sequenceable.hh
                                        continuable.hh)

set(SPRIGATITO_INTERFACE_HEADER         iterable.cc
                                        collectable.cc
                                        scannable.cc
                                        sequenceable.cc
                                        continuable.cc)

set(SPRIGATITO_IMPLEMENT_HEADER         )


set(SPRIGATITO_IMPLEMENT_SOURCE
    streamable.cc
    streamable.hh
        capable.cc
        capable.hh
        capable.template.character.hh
        continuation.hh
        continuation.template.unsigned.char.hh
        continuation.cc
        stream.cc
        stream.hh
        string.cc
        string.hh
)

add_library(pokemonism-sprigatito       ${SPRIGATITO_ROOT_HEADER}
                                        ${SPRIGATITO_ROOT_SOURCE}
                                        ${SPRIGATITO_IMPLEMENT_SOURCE})
