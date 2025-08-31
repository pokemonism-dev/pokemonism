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
#include <pokemonism/wattrel/generator.hh>
#include <pokemonism/wattrel/subscription.hh>

namespace pokemonism {
    namespace wattrel {

        namespace command {

            typedef pokemon::command::output    output;
            typedef pokemon::command::type      type;

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

            class subscription : public wattrel::subscription {
            public:     subscription(void) {}
            public:     ~subscription(void) override {}
            public:     subscription(const subscription & o) = delete;
            public:     subscription(subscription && o) noexcept = delete;
            public:     subscription & operator=(const subscription & o) = delete;
            public:     subscription & operator=(subscription && o) noexcept = delete;
            };

            class node : protected wattrel::node, public virtual command::envelope {
            public:     typedef command::envelope::message  message;
            public:     message * pop(void) const override = 0;
            public:     const message * peak(void) const override = 0;
            public:     virtual const exception * exceptionGet(void) const = 0;
            public:     node(void) {}
            public:     ~node(void) override {}
            public:     node(const node & o) = delete;
            public:     node(node && o) noexcept = delete;
            public:     node & operator=(const node & o) = delete;
            public:     node & operator=(node && o) noexcept = delete;
            };



        }



        // namespace command {

        // }
    }
}

#endif // __POKEMONISM_WATTREL_COMMAND_HH__
