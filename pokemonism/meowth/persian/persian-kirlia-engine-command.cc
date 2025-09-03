/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#include <pokemonism/pokemon/allocator.hh>
#include <pokemonism/meowth/persian.hh>

#include <pokemonism/ralts/kirlia/engine.hh>
#include <pokemonism/ralts/kirlia/gardevoir/engine.hh>
#include <pokemonism/ralts/kirlia/command.hh>

using namespace pokemonism;

namespace pokemonism {
    namespace persian {
        inline void terminator(void) {}
    }
}

int main(int argc, char ** argv) {


    kirlia::engine<gardevoir::engine>::on();


    constexpr kirlia::engine<gardevoir::engine>::command::subscription::event::handler::set subscriptionSet = {
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
            const pokemon::command * command = subscription.commandPop();
            delete command;
            kirlia::engine<gardevoir::engine>::off([](){});
        },
    };

    constexpr persian::command::event::handler::set eventSet = {
        [](pokemon::command & command, uint32 type, pokemon::command::envelope * envelope) -> void {
            pokemon::exception * exception = envelope->exceptionPop();
            printf("%p => complete => %s\n", pointof(command), envelope->completeChk() ? "true" : "false");
            printf("%p => execute => %d\n", pointof(command), envelope->executeCnt());
            printf("%p => exception => %p\n", pointof(command), exception);
            printf("%p => subscription\n", envelope->subscriptionGet());
            printf("%ld\n", primitivable::object::to::integer64(envelope->messagePop()));

            allocator::del(exception);
        }
    };

    kirlia::engine<gardevoir::engine>::reg(new persian::command(), kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);
    kirlia::engine<gardevoir::engine>::reg(new persian::command(), kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);
    kirlia::engine<gardevoir::engine>::reg(new persian::command(), 3, kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);
    kirlia::engine<gardevoir::engine>::reg(new persian::command(1004), 4, kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);
    kirlia::engine<gardevoir::engine>::reg(new persian::command(), 5, kirlia::subscription::property::release_object_on_rel | kirlia::subscription::property::release_on_del, eventSet);
    kirlia::engine<gardevoir::engine>::reg(new persian::command(1004), kirlia::subscription::property::release_on_del, eventSet, subscriptionSet);

    return kirlia::engine<gardevoir::engine>::run();
}
