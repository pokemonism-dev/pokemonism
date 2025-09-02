/**
 * @file            pokemonism/ralts/kirlia/event.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_RALTS_KIRLIA_EVENT_HH__
#define   __POKEMONISM_RALTS_KIRLIA_EVENT_HH__

#include <pokemonism.hh>

#include <pokemonism/ralts/subscription.hh>

namespace pokemonism {
    namespace kirlia {

        class event {
        public:     struct type {
                    public:     constexpr static uint32 gen = 0;
                    public:     constexpr static uint32 rel = 1;
                    public:     constexpr static uint32 reg = 2;
                    public:     constexpr static uint32 del = 3;
                    public:     constexpr static uint32 max = 4;
                    };
        public:     class subscription : public ralts::subscription {
                    public:     struct property {
                                public:     constexpr static uint32 release_object_on_rel   = (0x00000001U << 30U);
                                public:     constexpr static uint32 release_on_del          = (0x00000001U << 31U);
                                };
                    public:     subscription(void) {}
                    public:     ~subscription(void) override {}
                    public:     subscription(const kirlia::event::subscription & o) = delete;
                    public:     subscription(kirlia::event::subscription && o) noexcept = delete;
                    public:     kirlia::event::subscription & operator=(const kirlia::event::subscription & o) = delete;
                    public:     kirlia::event::subscription & operator=(kirlia::event::subscription && o) noexcept = delete;
                    };
        public:     virtual uint32 eventGet(void) const = 0;
        public:     event(void) {}
        public:     virtual ~event(void) {}
        public:     event(const kirlia::event & o) = delete;
        public:     event(kirlia::event && o) noexcept = delete;
        public:     kirlia::event & operator=(const kirlia::event & o) = delete;
        public:     kirlia::event & operator=(kirlia::event && o) noexcept = delete;
        };

    }

    namespace pokemon {
        using event = kirlia::event;
    }
}

#endif // __POKEMONISM_RALTS_KIRLIA_EVENT_HH__