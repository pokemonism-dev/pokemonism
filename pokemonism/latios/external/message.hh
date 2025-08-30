/**
 * @file        pokemonism/latios/external/message.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_LATIOS_EXTERNAL_MESSAGE__HH__
#define   __POKEMONISM_LATIOS_EXTERNAL_MESSAGE__HH__

#include <pokemonism/pokemon/exception.hh>

namespace pokemonism {
    namespace latios {
        namespace external {

            template <class format>
            class message {
            public:     virtual const exception * exceptionGet(void) const = 0;
            public:     message(void) {}
            public:     virtual ~message(void) {}
            public:     message(const message & o) = delete;
            public:     message(message && o) noexcept = delete;
            public:     message & operator=(const message & o) = delete;
            public:     message & operator=(message && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_EXTERNAL_MESSAGE__HH__
