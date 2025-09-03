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

#include <pokemonism/envelope.hh>

#include <pokemonism/interface/observable.hh>

namespace pokemonism {

    class event {
    public:     template <typename objectable, typename envelopeable = objectable::envelope> struct callback;
    public:     constexpr static uint32 max = 0;
    public:     virtual uint32 identifierGet(void) const = 0;
    public:     event(void) {}
    public:     virtual ~event(void) {}
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

    template <typename objectable, typename envelopeable>
    struct event::callback {
    public:     typedef void (*function)(const objectable &, uint32, envelopeable &);
    public:     function func;
    public:     callback(void) : func(nullptr) {}
    public:     explicit callback(function f) : func(f) {}
    };

}

#endif // __POKEMONISM_EVENT_HH__