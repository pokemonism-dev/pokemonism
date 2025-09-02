/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_COMMAND_HH__
#define   __POKEMONISM_GARDEVOIR_COMMAND_HH__

#include <pokemonism/pokemon/exception.hh>

#include <pokemonism/ralts/kirlia/command.hh>
#include <pokemonism/ralts/kirlia/gardevoir/event.hh>
#include <pokemonism/ralts/kirlia/gardevoir/envelope.hh>
#include <pokemonism/ralts/kirlia/gardevoir/subscription.hh>

#include <pokemonism/ralts/kirlia/gallade/command.hh>

namespace pokemonism {
    namespace gardevoir {
        namespace command {

            class event : public gardevoir::event, public kirlia::command::event {
            public:     struct type : public kirlia::command::event::type {};
            public:     class subscription : public kirlia::command::subscription {
                        public:     subscription(void) {}
                        public:     ~subscription(void) override {}
                        public:     subscription(const gardevoir::command::event::subscription & o) = delete;
                        public:     subscription(gardevoir::command::event::subscription && o) noexcept = delete;
                        public:     gardevoir::command::event::subscription & operator=(const gardevoir::command::event::subscription & o) = delete;
                        public:     gardevoir::command::event::subscription & operator=(gardevoir::command::event::subscription && o) noexcept = delete;
                        };
            public:     event(void) {}
            public:     ~event(void) override {}
            public:     event(const gardevoir::command::event & o) = delete;
            public:     event(gardevoir::command::event && o) noexcept = delete;
            public:     gardevoir::command::event & operator=(const gardevoir::command::event & o) = delete;
            public:     gardevoir::command::event & operator=(gardevoir::command::event && o) noexcept = delete;
            };

            class envelope : public gardevoir::envelope, public kirlia::command::envelope {
            public:     typedef kirlia::command::envelope::message  message;
            protected:  message * output;
            public:     inline kirlia::command::envelope::message * messagePop() override { return output; }
            public:     inline envelope(void) : output(nullptr) {}
            public:     inline ~envelope(void) override { pokemon_critical_exit_check(output != nullptr, output = nullptr); }
            public:     envelope(const gardevoir::command::envelope & o) = delete;
            public:     envelope(gardevoir::command::envelope & o) noexcept = delete;
            public:     gardevoir::command::envelope & operator=(const gardevoir::command::envelope & o) = delete;
            public:     gardevoir::command::envelope & operator=(gardevoir::command::envelope & o) noexcept = delete;
            };

            class subscription : public gardevoir::subscription, public kirlia::command::subscription {
            protected:  inline gallade::command::subscription * internal() const {
                            pokemon_develop_check(gardevoir::subscription::internal != nullptr && dynamic_cast<gallade::command::subscription *>(gardevoir::subscription::internal), exit(0));

                            return reinterpret_cast<gallade::command::subscription *>(gardevoir::subscription::internal);
                        }
            public:     inline explicit subscription(gallade::command::subscription * internal) : gardevoir::subscription(internal) {}
            public:     subscription(void) = delete;
            public:     ~subscription(void) override {}
            public:     subscription(const gardevoir::command::subscription & o) = delete;
            public:     subscription(gardevoir::command::subscription && o) noexcept = delete;
            public:     gardevoir::command::subscription & operator=(const gardevoir::command::subscription & o) = delete;
            public:     gardevoir::command::subscription & operator=(gardevoir::command::subscription && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_GARDEVOIR_COMMAND_HH__