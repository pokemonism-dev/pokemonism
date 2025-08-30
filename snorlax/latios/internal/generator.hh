/**
 * @file        pokemonism/latios/internal/generator.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__

// #include <pokemonism/latios/general/generator.hh>
// #include <pokemonism/latios/internal/event.hh>

#include <pokemonism/latios/package/pack.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            template <class object, class objectable, class generatable = void>
            class generator : public package::pack<object, objectable, generatable>::generator {
            public:     void clear(void) override {}
            public:     virtual int add(package::eventable<object, objectable, generatable>::generator::subscription * node) { return fail; }
            public:     virtual int del(package::eventable<object, objectable, generatable>::generator::subscription * node) { return fail; }
            public:     explicit generator(general::engine * engine) : package::eventable<object, objectable, generatable>::generator(engine) {}
            };



        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__
