/**
 * @file        pokemonism/pokemon/general/envelope.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERAL_ENVELOPE__HH__
#define   __POKEMONISM_POKEMON_GENERAL_ENVELOPE__HH__

#include <pokemonism/pokemon/envelope.hh>

namespace pokemonism {
    namespace pokemon {
        namespace general {

            template <class message = primitivable::object>
            class envelope : public pokemon::envelope {
            public:     const message & peak(void) const override = 0;
            public:     envelope(void) {}
            public:     ~envelope(void) override {}
            public:     envelope(const envelope & o) = delete;
            public:     envelope(envelope && o) noexcept = delete;
            public:     envelope & operator=(const envelope & o) = delete;
            public:     envelope & operator=(envelope && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_POKEMON_GENERAL_ENVELOPE__HH__
