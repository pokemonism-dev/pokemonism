/**
 * @file        pokemonism/latios/envelope.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_LATIOS_ENVELOPE__HH__
#define   __POKEMONISM_LATIOS_ENVELOPE__HH__

#include <pokemonism/pokemon/envelope.hh>
#include <pokemonism/pokemon/exception.hh>

#include <pokemonism/latios/message.hh>

namespace pokemonism {
    namespace latios {

        template <class objectable, class messageable = message<objectable>>
        class envelope : public pokemon::envelope {
        public:     const messageable & peak(void) const override = 0;
        public:     virtual messageable * pop(void) const = 0;
        public:     virtual const exception * exceptionGet(void) const = 0;
        public:     virtual uint32 eventGet(void) const = 0;
        public:     virtual objectable * objectGet(void) const  = 0;
        public:     virtual int processRet(void) const = 0;
        public:     envelope(void) {}
        public:     ~envelope(void) override {}
        public:     envelope(const envelope & o) = delete;
        public:     envelope(envelope && o) noexcept = delete;
        public:     envelope & operator=(const envelope & o) = delete;
        public:     envelope & operator=(envelope && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_LATIOS_ENVELOPE__HH__
