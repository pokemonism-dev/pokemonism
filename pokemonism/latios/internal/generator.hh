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

#include <pokemonism/latios/internal/engine.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            class generator {
            protected:  internal::engine * engine;
            public:     explicit generator(internal::engine * engine) : engine(engine) {}
            public:     generator(void) = delete;
            public:     virtual ~generator(void) {
                            engine = nullptr;
                        }
            public:     generator(const generator & o) = delete;
            public:     generator(generator && o) noexcept = delete;
            public:     generator & operator=(const generator & o) = delete;
            public:     generator & operator=(generator && o) noexcept = delete;
            };
        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__
