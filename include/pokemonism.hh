/**
 * @file        pokemonism.hh
 * @brief
 * @detalis
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM__HH__
#define   __POKEMONISM__HH__

#include <functional>
#include <exception>
#include <iostream>

namespace pokemon {
    typedef char                                    int8;
    typedef short                                   int16;
    typedef int                                     int32;
    typedef long                                    int64;

    typedef unsigned char                           uint8;
    typedef unsigned short                          uint16;
    typedef unsigned int                            uint32;
    typedef unsigned long                           uint64;

    // ReSharper disable once CppEnforceNestedNamespacesStyle
    namespace declaration {
        constexpr int                               infinite = -1;
        constexpr int                               invalid = -1;
        constexpr int                               fail = -1;
        constexpr int                               success = 0;
        namespace type {
            typedef __SIZE_TYPE__                   size;
            typedef decltype(nullptr)               null;
            namespace pointer {
                typedef __PTRDIFF_TYPE__            distance;
            }
            typedef char *                          string;

            template <typename description> using   function = std::function<description>;
            using                                   exception = std::exception;
            using                                   ostream = std::ostream;
        }
    }

    template <typename type> inline type * addressof(type & x) noexcept { return __builtin_addressof(x); }

}

#define pointof(o)                                  (&(o))
#define referenceof(o)                              (*(o))
#define valueof(o)                                  (*(o))

#endif // __POKEMONISM__HH__