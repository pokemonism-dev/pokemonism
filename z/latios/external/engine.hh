/**
 * @file        pokemonism/latios/external/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_LATIOS_EXTERNAL_ENGINE__HH__
#define   __POKEMONISM_LATIOS_EXTERNAL_ENGINE__HH__

#include <pokemonism/pokemon.hh>

#include <pokemonism/latios/command.hh>

namespace pokemonism {
    namespace latios {
        namespace external {

            class engine {
            public:     template <class output = primitivable::object>
                        subscription<pokemon::general::command<output>, envelope<output, latios::message<output>>> * reg(pokemon::general::command<output> * command, uint32 properties, const command::callback<output>::type *, uint32 n);
            public:     engine(void);
            public:     virtual ~engine(void);
            public:     engine(const engine & o) = delete;
            public:     engine(engine && o) noexcept = delete;
            public:     engine & operator=(const engine & o) = delete;
            public:     engine & operator=(engine && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_EXTERNAL_ENGINE__HH__