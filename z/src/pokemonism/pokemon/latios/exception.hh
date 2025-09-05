/**
 * @file        pokemon/latios/exception.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EXCEPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EXCEPTION__HH__

#include <pokemon/exception.hh>

#define latios_exception_class_quick_declare(first, second)                         \
namespace pokemon { namespace latios { namespace exception { namespace first {      \
using second = pokemon::exception;                                                  \
} } } }

#define latios_single_namespace_exception_class_quick_declare(first)                \
namespace pokemon { namespace latios { namespace exception {                        \
using first = pokemon::exception;                                                   \
} } }

latios_exception_class_quick_declare(deleted, event);
latios_exception_class_quick_declare(unsupported, event);

#endif // __POKEMONISM_POKEMON_LATIOS_EXCEPTION__HH__