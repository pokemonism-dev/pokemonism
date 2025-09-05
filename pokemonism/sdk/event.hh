/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SDK_EVENT_HH__
#define   __POKEMONISM_SDK_EVENT_HH__

#include <pokemonism.hh>

namespace pokemonism {
    class event {
    public:     class subscription;
    public:     virtual unsigned int identifierGet(void) const = 0;
    public:     inline event(void);
    public:     inline virtual ~event(void);
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

    class event::subscription {
    public:     virtual bool cancel(void) = 0;
    public:     inline subscription(void);
    public:     inline virtual ~subscription(void);
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };

    inline event::event(void) {

    }

    inline event::~event(void) {

    }

    inline event::subscription::subscription(void) {

    }

    inline event::subscription::~subscription(void) {

    }
}

#endif // __POKEMONISM_SDK_EVENT_HH__