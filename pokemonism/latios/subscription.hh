/**
 * @file        pokemonism/latios/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 *
 */

#ifndef   __POKEMONISM_LATIOS_SUBSCRIPTION__HH__
#define   __POKEMONISM_LATIOS_SUBSCRIPTION__HH__

#include <pokemonism/mareep.hh>
#include <pokemonism/pokemon/general/envelope.hh>

namespace pokemonism {
    namespace latios {

        template <class objectable, class messageable = primitivable::object>
        class subscription : public virtual pokemonism::subscription {
        public:     struct property {
        public:     constexpr static uint32 release_on_del          = (0x00000001U << 30U);
        public:     constexpr static uint32 release_object_on_rel   = (0x00000001U << 31U);
        };
        public:     class envelope : public pokemon::general::envelope<messageable> {
                    public:     const messageable & peak(void) const override = 0;
                    public:     virtual messageable * pop(void) const = 0;
                    public:     virtual const exception * exceptionGet(void) const = 0;
                    public:     virtual int processRet(void) const = 0;
                    public:     envelope(void) {}
                    public:     ~envelope(void) override {}
                    public:     envelope(const envelope & o) = delete;
                    public:     envelope(envelope && o) noexcept = delete;
                    public:     envelope & operator=(const envelope & o) = delete;
                    public:     envelope & operator=(envelope && o) noexcept = delete;
                    };
        public:     bool cancel(void) override = 0;
        public:     virtual const objectable * objectGet(void) const = 0;
        public:     subscription(void) {}
        public:     ~subscription(void) override {}
        public:     subscription(const subscription<objectable> & o) = delete;
        public:     subscription(subscription<objectable> && o) noexcept = delete;
        public:     subscription<objectable> & operator=(const subscription<objectable> & o) = delete;
        public:     subscription<objectable> & operator=(subscription<objectable> && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_LATIOS_SUBSCRIPTION__HH__