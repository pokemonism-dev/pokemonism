/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERIC_ENVELOPE_HH__
#define   __POKEMONISM_POKEMON_GENERIC_ENVELOPE_HH__

#include <pokemonism/pokemon/envelope.hh>
#include <pokemonism/pokemon/message.hh>

namespace pokemonism {
    namespace pokemon {
        namespace generic {

            template <class messageable = pokemonism::message>
            class envelope : public virtual pokemon::envelope {
            public:     typedef messageable     message;
            public:     message * pop(void) const override = 0;
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

#endif // __POKEMONISM_POKEMON_GENERIC_ENVELOPE_HH__