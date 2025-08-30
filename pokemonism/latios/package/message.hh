/**
 * @file        pokemonism/latios/package/message.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_MESSAGE__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_MESSAGE__HH__

#include <pokemonism/latios/message.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class format = external::message::format>
            class message : public latios::message<format> {
            public:     message<format> * pop(void) const override = 0;
            public:     const message<format> * peak(void) const override = 0;
            public:     const exception * exceptionGet(void) const override = 0;
            public:     message(void) {}
            public:     ~message(void) override {}
            public:     message(const message<format> & o) = delete;
            public:     message(message<format> && o) noexcept = delete;
            public:     message<format> & operator=(const message<format> & o) = delete;
            public:     message<format> & operator=(message<format> && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_MESSAGE__HH__
