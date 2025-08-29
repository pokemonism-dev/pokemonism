/**
 * @file        pokemonism/latios/general/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_LATIOS_GENERAL_ENGINE__HH__
#define   __POKEMONISM_LATIOS_GENERAL_ENGINE__HH__

#include <pokemonism/latios/external/engine.hh>

namespace pokemonism {
    namespace latios {
        namespace general {

            class engine : public external::engine {
            public:     engine(void);
            public:     ~engine(void) override;
            public:     engine(const engine & o) = delete;
            public:     engine(engine && o) noexcept = delete;
            public:     engine & operator=(const engine & o) = delete;
            public:     engine & operator=(engine && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_GENERAL_ENGINE__HH__