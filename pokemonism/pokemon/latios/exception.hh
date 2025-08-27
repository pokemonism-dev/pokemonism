//
// Created by snorlax on 25. 8. 27..
//

#ifndef POKEMONISM_EXCEPTION_HH
#define POKEMONISM_EXCEPTION_HH

#include <pokemon/exception.hh>

#define latios_exception_class_quick_declare(first, second)                         \
namespace pokemon { namespace latios { namespace exceptional { namespace first {    \
using second = pokemon::exception;                                                  \
} } } }

#define latios_single_namespace_exception_class_quick_declare(first)                \
namespace pokemon { namespace latios { namespace exceptional {                      \
using first = pokemon::exception;                                                   \
} } }

latios_exception_class_quick_declare(deleted, event);

#endif //POKEMONISM_EXCEPTION_HH