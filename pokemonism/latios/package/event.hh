/**
 * @file        pokemonism/latios/package/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_EVENT__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_EVENT__HH__

#include <pokemonism/latios/general/queue.hh>
#include <pokemonism/latios/package/eventable.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object, class objectable, class generatable = void>
            class event : public eventable<object, objectable, generatable>::event {
            public:     int on(void) override = 0;
            public:     event(uint32 tag, eventable<object, objectable, generatable>::node * node) : eventable<object, objectable, generatable>::event(tag, node) {}
            public:     event(void) = delete;
            public:     ~event(void) override {}
            public:     event(const event<object, objectable, generatable> & o) = delete;
            public:     event(event<object, objectable, generatable> && o) noexcept = delete;
            public:     event<object, objectable, generatable> & operator=(const event<object, objectable, generatable> & o) = delete;
            public:     event<object, objectable, generatable> & operator=(event<object, objectable, generatable> && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_EVENT__HH__
