/**
 * @file            pokemonism/event.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_EVENT_HH__
#define   __POKEMONISM_EVENT_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class event {
    public:     constexpr static uint32 max = 0;
    public:     virtual uint32 identifierGet(void) const = 0;
    public:     event(void) {}
    public:     virtual ~event(void) {}
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_EVENT_HH__