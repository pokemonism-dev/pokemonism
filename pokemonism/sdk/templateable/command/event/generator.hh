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

    template <class commandable, typename outputable>
    command::subscription<commandable, outputable> * command::event::generator::commandReg(command::event::generator * o, command::subscription<commandable, outputable> * subscription) {
        o->reg(subscription);

        return subscription;
    }

    template <class commandable, typename outputable>
    command::subscription<commandable, outputable> * command::event::generator::commandReg(command::event::generator * o, commandable * object, unsigned int properties, const typename command::event::callback<commandable, outputable>::set & eventSet) {
        pokemon_develop_check(object == nullptr, return nullptr);

        return command::event::generator::commandReg(o, new command::internal::subscription<commandable, outputable>(object, properties, eventSet));
    }

    template <class commandable, typename outputable>
    command::subscription<commandable, outputable> * command::event::generator::commandReg(command::event::generator * o, commandable * object, unsigned int properties, const typename command::event::callback<commandable, outputable>::set & eventSet, typename command::subscription<commandable, outputable>::state::callback::function subscriptionOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        return command::event::generator::commandReg(o, new command::internal::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn));
    }

    template <class commandable, typename outputable>
    command::subscription<commandable, outputable> * command::event::generator::commandReg(command::event::generator * o, commandable * object, unsigned int properties, const typename command::event::callback<commandable, outputable>::set & eventSet, typename command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        return command::event::generator::commandReg(o, new command::internal::subscription<commandable, outputable>(object, properties, eventSet, subscriptionReleaseOn));
    }

    template <class commandable, typename outputable>
    command::subscription<commandable, outputable> * command::event::generator::commandReg(command::event::generator * o, commandable * object, unsigned int properties, const typename command::event::callback<commandable, outputable>::set & eventSet, typename command::subscription<commandable, outputable>::state::callback::function subscriptionOn, typename command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        return command::event::generator::commandReg(o, new command::internal::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn));
    }

    inline command::event::generator::generator(pokemonism::sdk::engine * engine) : pokemonism::sdk::command::event::generator(engine) {

    }

    inline command::event::generator::~generator(void) {

    }

}

#endif // __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_EVENT_GENERATOR_HH__