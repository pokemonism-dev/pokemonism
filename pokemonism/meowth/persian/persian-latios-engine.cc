/**
 * @file        meowth/persian/persian-latios-engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#include <pokemonism/latios.hh>

#include <pokemonism/latios/internal/command/node.hh>
#include <pokemonism/latios/internal/command/event.hh>
#include <pokemonism/latios/internal/command/generator.hh>
#include <pokemonism/latios/internal/command/subscription.hh>

#include <pokemonism/latios/internal/process/event.hh>
#include <pokemonism/latios/internal/descriptor/event.hh>
#include <pokemonism/latios/internal/socket/event.hh>

using namespace pokemonism::latios::internal;

namespace pokemonism {
    namespace meowth {
        namespace persian {
            class command : public pokemonism::command {
            public:     primitivable::object * operator()(void) override { return primitivable::object::object::gen(random()); }
            };
        }
    }
}

using namespace pokemonism::meowth;

int main(int argc, char ** argv) {
    srandom(time(nullptr));
    {
        try {
            persian::command o;
            command::subscription::callback callback[command::event::type::max] = { 0, };
            command::subscription subscription(pointof(o), pokemonism::declaration::none, callback, command::event::type::max);
            command::node node;
            command::generator generator(nullptr);
            command::event event(1, nullptr);
        } catch (const pokemonism::exception & e) {
            printf("pokemon exception\n");
        } catch (...) {
            printf("error\n");
        }

        printf("%u\n", command::event::type::max);
    }


    {
        try {
            process::event event(1, nullptr);
        } catch (const pokemonism::exception & e) {
            printf("pokemon exception\n");
        } catch (...) {
            printf("error\n");
        }

        printf("%u\n", process::event::type::max);
    }

    {
        try {
            socket::event event(1, nullptr);
        } catch (const pokemonism::exception & e) {
            printf("pokemon exception\n");
        } catch (...) {
            printf("error\n");
        }
        printf("%u\n", socket::event::type::max);
    }

    {
        try {
            descriptor::event event(1, nullptr);
        } catch (const pokemonism::exception & e) {
            printf("pokemon exception\n");
        } catch (...) {
            printf("error\n");
        }
        printf("%u\n", descriptor::event::type::max);
    }

    return pokemonism::engine::run();
}