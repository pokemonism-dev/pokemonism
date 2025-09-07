/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_EVENT_GENERATOR_HH__
#define   __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_EVENT_GENERATOR_HH__

#include <pokemonism/sdk/templateable/command.hh>

namespace pokemonism::sdk::templateable {

    template <typename outputable, class commandable>
    command::subscription<outputable, commandable> * command::event::generator::reg(command::subscription<outputable, commandable> * subscription) {
        pokemonism::sdk::command::event::generator::reg(subscription);

        return subscription;
    }

    template <typename outputable, class commandable>
    command::subscription<outputable, commandable> * command::event::generator::reg(commandable * object, unsigned int properties, const typename command::event::callback<outputable, commandable>::set & eventSet) {
        pokemon_develop_check(object == nullptr, return nullptr);

        return reg(new command::internal::subscription<outputable, commandable>(object, properties, eventSet));
    }

    template <typename outputable, class commandable>
    command::subscription<outputable, commandable> * command::event::generator::reg(commandable * object, unsigned int properties, const typename command::event::callback<outputable, commandable>::set & eventSet, typename command::subscription<outputable, commandable>::state::callback::function subscriptionOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        return reg(new command::internal::subscription<outputable, commandable>(object, properties, eventSet, subscriptionOn));
    }

    template <typename outputable, class commandable>
    command::subscription<outputable, commandable> * command::event::generator::reg(commandable * object, unsigned int properties, const typename command::event::callback<outputable, commandable>::set & eventSet, typename command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        return reg(new command::internal::subscription<outputable, commandable>(object, properties, eventSet, subscriptionReleaseOn));
    }

    template <typename outputable, class commandable>
    command::subscription<outputable, commandable> * command::event::generator::reg(commandable * object, unsigned int properties, const typename command::event::callback<outputable, commandable>::set & eventSet, typename command::subscription<outputable, commandable>::state::callback::function subscriptionOn, typename command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        return reg(new command::internal::subscription<outputable, commandable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn));
    }

    inline command::event::generator::generator(pokemonism::sdk::engine * engine) : pokemonism::sdk::command::event::generator(engine) {

    }

    inline command::event::generator::~generator(void) {

    }

}

#endif // __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_EVENT_GENERATOR_HH__