/**
 * @file        pokemonism/latios/general/processor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_GENERAL_PROCESSOR__HH__
#define   __POKEMONISM_LATIOS_GENERAL_PROCESSOR__HH__

#include <pokemonism/latios/general/event.hh>
#include <pokemonism/latios/general/subscription.hh>

namespace pokemonism {
    namespace latios {
        namespace general {

            class processor {
            public:     processor(void) {}
            public:     virtual ~processor(void) {}
            public:     processor(const processor & o) = delete;
            public:     processor(processor && o) noexcept = delete;
            public:     processor & operator=(const processor & o) = delete;
            public:     processor & operator=(processor && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_GENERAL_PROCESSOR__HH__
