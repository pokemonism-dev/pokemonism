/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_COMMAND_HH__
#define   __POKEMONISM_WATTREL_COMMAND_HH__

#include <pokemonism/pokemon/command.hh>
#include <pokemonism/pokemon/exception.hh>

#include <pokemonism/wattrel/node.hh>
#include <pokemonism/wattrel/event.hh>
#include <pokemonism/wattrel/generator.hh>
#include <pokemonism/wattrel/subscription.hh>

namespace pokemonism {
    namespace wattrel {
        namespace command {

            typedef pokemon::command::output    output;
            typedef pokemon::command::callback  callback;

            class node;

            class envelope : public pokemon::command::envelope {
            public:     typedef command::output     message;
            public:     message * pop(void) const override = 0;
            public:     const message * peak(void) const override = 0;
            public:     envelope(void) {}
            public:     ~envelope(void) override {}
            public:     envelope(const envelope & o) = delete;
            public:     envelope(envelope && o) noexcept = delete;
            public:     envelope & operator=(const envelope & o) = delete;
            public:     envelope & operator=(envelope && o) noexcept = delete;
            };

            class generator : public wattrel::generator {
            public:     generator(void) {}
            public:     ~generator(void) override {}
            public:     generator(const generator & o) = delete;
            public:     generator(generator && o) noexcept = delete;
            public:     generator & operator=(const generator & o) = delete;
            public:     generator & operator=(generator && o) noexcept = delete;
            };

            class event: public wattrel::event {
            public:     typedef wattrel::event::type    type;
            public:     inline event(uint32 id, wattrel::command::node * node);
            public:     ~event(void) override {}
            public:     event(const event & o) = delete;
            public:     event(event && o) noexcept = delete;
            public:     event & operator=(const event & o) = delete;
            public:     event & operator=(event && o) noexcept = delete;
            };

            class subscription : public wattrel::subscription {
            protected:  pokemon::command * object;
            protected:  command::callback callbacks[command::event::type::max];
            public:     inline explicit subscription(pokemon::command * object, uint32 properties, const command::callback * callbacks, uint32 n) : wattrel::subscription(properties), object(object), callbacks() {
                            if (callbacks == nullptr || n == 0 || n > command::event::type::max) throw pokemon::exception();

                            memcpy(this->callbacks, callbacks, sizeof(command::callback) * n);
                            if (n < command::event::type::max) memset(this->callbacks + n, 0, (command::event::type::max - n) * sizeof(command::callback));
                        }
            public:     ~subscription(void) override {
                            // TODO: IMPLEMENT THIS
                            // if (properties & command::event:property::release_object_on_rel);
                            // object
                            memset(this->callbacks, 0, sizeof(command::callback) * command::event::type::max);
                        }
            public:     subscription(const subscription & o) = delete;
            public:     subscription(subscription && o) noexcept = delete;
            public:     subscription & operator=(const subscription & o) = delete;
            public:     subscription & operator=(subscription && o) noexcept = delete;
            };

            class node : public wattrel::node, public virtual command::envelope {
            public:     typedef command::envelope::message  message;
            public:     message * pop(void) const override = 0;
            public:     const message * peak(void) const override = 0;
            public:     virtual const exception * exceptionGet(void) const = 0;
            public:     explicit node(wattrel::command::subscription * subscription) : wattrel::node(static_cast<wattrel::subscription *>(subscription)) {}
            public:     ~node(void) override {}
            public:     node(const node & o) = delete;
            public:     node(node && o) noexcept = delete;
            public:     node & operator=(const node & o) = delete;
            public:     node & operator=(node && o) noexcept = delete;
            };


            inline event::event(uint32 id, wattrel::command::node * node) : wattrel::event(id, static_cast<wattrel::node *>(node)) {
            }

        }
    }
}

#endif // __POKEMONISM_WATTREL_COMMAND_HH__
