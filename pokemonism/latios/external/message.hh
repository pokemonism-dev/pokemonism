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

#include <primitivable.hh>

#include <pokemonism/pokemon/general/message.hh>
#include <pokemonism/pokemon/exception.hh>

namespace pokemonism {
    namespace latios {
        namespace external {

            template <class formattable = primitivable::object>
            class message : public pokemon::general::message<formattable> {
            public:     message<formattable> * pop(void) const override = 0;
            public:     const message * peak(void) const override = 0;
            public:     const exception * exceptionGet(void) const override = 0;
            public:     message(void) {}
            public:     ~message(void) override {}
            public:     message(const message & o) = delete;
            public:     message(message && o) noexcept = delete;
            public:     message & operator=(const message & o) = delete;
            public:     message & operator=(message && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_EXTERNAL_MESSAGE__HH__
