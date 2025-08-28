cmake_minimum_required(VERSION 3.28.3)

project(sprigatito CXX)
set(CMAKE_CXX_STANDARD 23)

set(SPRIGATITO_SOURCE                       reference.cc)

set(SPRIGATITO_HEADER                       reference.hh)

set(FLORAGATO_SOURCE                        floragato/stream.cc
                                            floragato/buffer.cc
                                            floragato/string.cc)

set(FLORAGATO_SOURCE                        floragato/stream.hh
                                            floragato/buffer.hh
                                            floragato/string.hh)

set(SPRIGATITO_IMPLEMENT_SOURCE

        wide/string.cc
        wide/string.hh
        stream.cc
        stream.hh
        string.cc
        string.hh
        buffer.cc
        buffer.hh
        collectable.cc
        collectable.hh
        containable.cc
        containable.hh
        scannable.cc
        scannable.hh
        iterator.cc
        iterator.hh
        traversable.cc
        traversable.hh
        sequenceable.cc
        sequenceable.hh
        memorizable.cc
        continuable.hh)

add_library(sprigatito-pokemon-dev                      ${SPRIGATITO_SOURCE}
        ${SPRIGATITO_HEADER}
        ${SPRIGATITO_IMPLEMENT_SOURCE})
