/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#include "generator.hh"

#include "../../engine.hh"

namespace pokemonism::sdk {

    command::event::subscription * command::event::generator::reg(command::event::subscription * subscription) {
        pokemon_develop_check(subscription == nullptr, return nullptr);

        add(subscription);

        engine->add(eventGen(command::event::type::execute, subscription));

        return subscription;
    }

    command::event::subscription * command::event::generator::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet) {
        pokemon_develop_check(object == nullptr, return nullptr);

        command::event::internal::subscription * subscription = new command::event::internal::subscription(object, properties, eventSet);

        add(subscription);

        engine->add(eventGen(command::event::type::execute, subscription));

        return subscription;
    }

    command::event::subscription * command::event::generator::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        command::event::internal::subscription * subscription = new command::event::internal::subscription(object, properties, eventSet, subscriptionOn);

        add(subscription);

        engine->add(eventGen(command::event::type::execute, subscription));

        return subscription;
    }

    command::event::subscription * command::event::generator::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        command::event::internal::subscription * subscription = new command::event::internal::subscription(object, properties, eventSet, subscriptionReleaseOn);

        add(subscription);

        engine->add(eventGen(command::event::type::execute, subscription));

        return subscription;
    }

    command::event::subscription * command::event::generator::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) {
        pokemon_develop_check(object == nullptr, return nullptr);

        command::event::internal::subscription * subscription = new command::event::internal::subscription(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn);

        add(subscription);

        engine->add(eventGen(command::event::type::execute, subscription));

        return subscription;
    }

}
