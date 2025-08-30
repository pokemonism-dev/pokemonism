/**
 * @file        pokemonism/pokemon/general/message.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERAL_MESSAGE__HH__
#define   __POKEMONISM_POKEMON_GENERAL_MESSAGE__HH__

#include <pokemon/message.hh>

namespace pokemonism {
    namespace pokemon {
        namespace general {

            template <typename formattable = primitivable::object>
            class message : public pokemon::message {
            public:     const formattable & peak(void) const override = 0;
            public:     message(void) {}
            public:     ~message(void) override {}
            public:     message(const message<formattable> & o) = delete;
            public:     message(message<formattable> && o) noexcept = delete;
            public:     message<formattable> & operator=(const message<formattable> & o) = delete;
            public:     message<formattable> & operator=(message<formattable> && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_POKEMON_GENERAL_MESSAGE__HH__
