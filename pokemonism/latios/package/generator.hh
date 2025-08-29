/**
 * @file        pokemonism/latios/package/generatable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_GENERATABLE__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_GENERATABLE__HH__

#include <pokemonism/latios/general/generator.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object, class node>
            class generator : public general::generator {
            public:     typedef node        subscription;
            public:     uint64 size;
            public:     node * head;
            public:     node * tail;
            public:     explicit generator(general::engine * engine) : general::generator(engine), size(0), head(nullptr), tail(nullptr) {}
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_GENERATABLE__HH__
