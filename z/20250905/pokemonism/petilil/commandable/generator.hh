/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_PETILIL_COMMANDABLE_GENERATOR_HH__
#define   __POKEMONISM_PETILIL_COMMANDABLE_GENERATOR_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {
    inline petilil::commandable::subscription * petilil::commandable::generator::reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet) {
        pokemon_training_check(object == nullptr, return nullptr);

        petilil::commandable::modifiable::subscription * subscription = new petilil::commandable::modifiable::subscription(object, properties, callbackSet);

        add(subscription);

        return subscription;
    }

    inline petilil::commandable::subscription * petilil::commandable::generator::reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on) {
        pokemon_training_check(object == nullptr, return nullptr);

        petilil::commandable::modifiable::subscription * subscription = new petilil::commandable::modifiable::subscription(object, properties, callbackSet, on);

        add(subscription);

        return subscription;
    }

    inline petilil::commandable::subscription * petilil::commandable::generator::reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn) {
        pokemon_training_check(object == nullptr, return nullptr);

        petilil::commandable::modifiable::subscription * subscription = new petilil::commandable::modifiable::subscription(object, properties, callbackSet, modifiableOn);

        add(subscription);

        return subscription;
    }

    inline petilil::commandable::subscription * petilil::commandable::generator::reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn) {
        pokemon_training_check(object == nullptr, return nullptr);

        petilil::commandable::modifiable::subscription * subscription = new petilil::commandable::modifiable::subscription(object, properties, callbackSet, on, modifiableOn);

        add(subscription);

        return subscription;
    }

    inline petilil::commandable::generator::generator(petilil::event::engine * engine) : petilil::event::generator(engine) {

    }

    petilil::commandable::generator::generator(void) {

    }

    petilil::commandable::generator::~generator(void) {

    }
}

#endif // __POKEMONISM_PETILIL_COMMANDABLE_GENERATOR_HH__