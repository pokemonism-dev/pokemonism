/**
 * @file        pokemonism/latios/internal/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/latios/general/queue.hh>
#include <pokemonism/latios/internal/pack.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            template <class object, class objectable = pokemonism::command, class generatable = void>
            class event : public internal::pack<object, objectable, generatable>::event {
            public:     event(uint32 tag, package::eventable<object, objectable, generatable>::node * node) : internal::pack<object, objectable, generatable>::event(tag, node) {}
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

#endif // __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__
