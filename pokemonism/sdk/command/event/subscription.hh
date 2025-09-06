/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMAND_EVENT_SUBSCRIPTION_HH__
#define   __POKEMONISM_SDK_COMMAND_EVENT_SUBSCRIPTION_HH__

#include <pokemonism/sdk/command/event.hh>

namespace pokemonism::sdk {

    inline bool command::event::subscription::executeSet(void) {
        count = count + 1;

        status = status | command::event::subscription::state::complete;

        return true;
    }

    inline command::event::subscription::subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet) : pokemonism::sdk::event::subscription(properties), object(object), eventSet(eventSet), count(declaration::zero) {
        pokemon_develop_check(object == nullptr, (void)(0));
    }

    inline command::event::subscription::subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) : pokemonism::sdk::event::subscription(properties, reinterpret_cast<pokemonism::sdk::event::subscription::state::callback::function>(subscriptionOn)), object(object), eventSet(eventSet), count(declaration::zero) {
        pokemon_develop_check(object == nullptr, (void)(0));
    }

    inline command::event::subscription::subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::event::subscription(properties, reinterpret_cast<pokemonism::sdk::event::subscription::state::callback::function>(subscriptionReleaseOn)), object(object), eventSet(eventSet), count(declaration::zero) {
        pokemon_develop_check(object == nullptr, (void)(0));
    }

    inline command::event::subscription::subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::event::subscription(properties, reinterpret_cast<pokemonism::sdk::event::subscription::state::callback::function>(subscriptionReleaseOn)), object(object), eventSet(eventSet), count(declaration::zero) {
        pokemon_develop_check(object == nullptr, (void)(0));
    }

    inline command::event::subscription::subscription(void) : object(nullptr) {

    }

    inline command::event::subscription::~subscription(void) {
    }

}

#endif // __POKEMONISM_SDK_COMMAND_EVENT_SUBSCRIPTION_HH__