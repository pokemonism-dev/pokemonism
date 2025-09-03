/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#include <pokemonism/meowth/persian.hh>

#include <pokemonism/ralts/kirlia/engine.hh>
#include <pokemonism/ralts/kirlia/command.hh>

using namespace pokemonism;

namespace pokemonism {
    namespace persian {
        inline void terminator(void) {}
    }
}

int main(int argc, char ** argv) {
    kirlia::engine::on();

    constexpr kirlia::command::subscription::event::handler::set subscriptionSet = {
        [](const kirlia::command::subscription & subscription, uint32 type, const pokemon::exception * exception) -> void {
            printf("gen\n");
        },
        [](const kirlia::command::subscription & subscription, uint32 type, const pokemon::exception * exception) -> void {
            printf("reg\n");
        },
        [](const kirlia::command::subscription & subscription, uint32 type, const pokemon::exception * exception) -> void {
            printf("exception\n");
        },
        [](const kirlia::command::subscription & subscription, uint32 type, const pokemon::exception * exception) -> void {
            printf("del\n");
        },
        [](kirlia::command::poppable::subscription & subscription, uint32 type, const pokemon::exception * exception) -> void {
            printf("rel\n");
            pokemon::command * command = subscription.commandPop();
            delete command;
            kirlia::engine::off([](){});
        },
    };

    constexpr persian::command::event::handler::set eventSet = {
        [](pokemon::command & command, uint32 type, pokemon::command::envelope * envelope) -> void {

            printf("%ld\n", primitivable::object::to::integer64(envelope->messagePop()));
        }
    };

    kirlia::engine::reg(new persian::command(), kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);

    kirlia::engine::reg(new persian::command(), kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);

    kirlia::engine::reg(new persian::command(), 3, kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);
    kirlia::engine::reg(new persian::command(1004), 4, kirlia::subscription::property::release_on_del, eventSet, subscriptionSet);
    kirlia::engine::reg(new persian::command(), 5, kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);

    kirlia::engine::reg(new persian::command(1004), kirlia::subscription::property::release_on_del, eventSet, subscriptionSet);

    return kirlia::engine::run();
}
