/**
 * @file            pokemonism/ralts/kirlia/command.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_KIRLIA_COMMAND_HH__
#define   __POKEMONISM_KIRLIA_COMMAND_HH__


#include <pokemonism/ralts/kirlia/event.hh>

#include <pokemonism/ralts/kirlia/envelope.hh>
#include <pokemonism/ralts/kirlia/subscription.hh>
#include <pokemonism/pokemon/command.hh>

namespace pokemonism {
    namespace kirlia {
        namespace command {

            class subscription;

            class event : public virtual kirlia::event {
            public:     struct type : public kirlia::event::type {
                        public:     constexpr static uint32 execute     = kirlia::event::type::max;
                        public:     constexpr static uint32 max         = kirlia::event::type::max + 1;
                        };
            public:     typedef kirlia::command::subscription           subscription;
            public:     inline event(void) {}
            public:     inline ~event(void) override {}
            public:     event(const kirlia::command::event & o) = delete;
            public:     event(kirlia::command::event && o) noexcept = delete;
            public:     kirlia::command::event & operator=(const kirlia::command::event & o) = delete;
            public:     kirlia::command::event & operator=(kirlia::command::event && o) noexcept = delete;
            };

            class envelope : public virtual kirlia::envelope {
            public:     typedef kirlia::envelope::message   message;
            public:     kirlia::command::envelope::message * messagePop(void) override = 0;
            public:     inline envelope(void) {}
            public:     inline ~envelope(void) override {}
            public:     envelope(const kirlia::command::envelope & o) = delete;
            public:     envelope(kirlia::command::envelope & o) noexcept = delete;
            public:     kirlia::command::envelope & operator=(const kirlia::command::envelope & o) = delete;
            public:     kirlia::command::envelope & operator=(kirlia::command::envelope & o) noexcept = delete;
            };

            class subscription : public virtual kirlia::subscription {
            public:     subscription(void) {}
            public:     ~subscription(void) override {}
            public:     subscription(const kirlia::command::subscription & o) = delete;
            public:     subscription(kirlia::command::subscription && o) noexcept = delete;
            public:     kirlia::command::subscription & operator=(const kirlia::command::subscription & o) = delete;
            public:     kirlia::command::subscription & operator=(kirlia::command::subscription && o) noexcept = delete;
            };
        }
    }
}

#endif // __POKEMONISM_KIRLIA_COMMAND_HH__