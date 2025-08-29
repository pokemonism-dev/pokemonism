/**
* @file        pokemonism/latios/external/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_EXTERNAL_EVENT__HH__
#define   __POKEMONISM_LATIOS_EXTERNAL_EVENT__HH__

#include <pokemonism/mareep.hh>

#include <pokemonism/latios/event.hh>

namespace pokemonism {
    namespace latios {
        namespace external {

            template <class objectable>
            class event : public virtual pokemonism::event {
            public:     constexpr static uint32     gen = 0;
            public:     constexpr static uint32     rel = 1;
            public:     constexpr static uint32     add = 2;
            public:     constexpr static uint32     del = 3;
            public:     constexpr static uint32     max = 4;
            public:     event(void) {}
            public:     ~event(void) override {}
            public:     event(const event<objectable> & o) = delete;
            public:     event(event<objectable> && o) noexcept = delete;
            public:     event<objectable> & operator=(const event<objectable> & o) = delete;
            public:     event<objectable> & operator=(event<objectable> && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_EXTERNAL_EVENT__HH__