/**
 * @file        pokemonism/latios/message.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_LATIOS_MESSAGE__HH__
#define   __POKEMONISM_LATIOS_MESSAGE__HH__

#include <pokemonism/pokemon/general/message.hh>
#include <pokemonism/pokemon/exception.hh>

#include <pokemonism/latios/external/message/format.hh>

namespace pokemonism {
    namespace latios {

        template <class format = external::message::format>
        class message : public pokemon::general::message<format> {
        public:     const format & peak(void) const override = 0;
        public:     virtual const format & pop(void) const = 0;
        public:     virtual const exception * exceptionGet(void) const = 0;
        public:     message(void) {}
        public:     ~message(void) override {}
        public:     message(const message & o) = delete;
        public:     message(message && o) noexcept = delete;
        public:     message & operator=(const message & o) = delete;
        public:     message & operator=(message && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_LATIOS_MESSAGE__HH__
