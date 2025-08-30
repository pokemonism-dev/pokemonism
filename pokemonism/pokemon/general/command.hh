/**
 * @file        pokemonism/pokemon/general/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERA_COMMAND__HH__
#define   __POKEMONISM_POKEMON_GENERA_COMMAND__HH__

#include <pokemonism/commandable.hh>

namespace pokemonism {
    namespace pokemon {
        namespace general {

            template <class output = primitivable::object>
            class command : public commandable {
            public:     output * operator()(void) override = 0;
            public:     inline command(void) {}
            public:     inline ~command(void) override {}
            public:     command(const command & o) = delete;
            public:     command(command && o) noexcept = delete;
            public:     command & operator=(const command & o) = delete;
            public:     command & operator=(command && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_POKEMON_GENERA_COMMAND__HH__