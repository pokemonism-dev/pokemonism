/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_PETILIL_COMMANDABLE_SUBSCRIPTION_HH__
#define   __POKEMONISM_PETILIL_COMMANDABLE_SUBSCRIPTION_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {

    inline void petilil::commandable::subscription::executeSet(void) {
        count = count + 1;

        status = status | petilil::commandable::subscription::state::complete;
    }

    inline void petilil::commandable::subscription::callbackOn(petilil::commandable::link * o, unsigned int type, pokemon::faint * e) {
        pokemon_training_check(o == nullptr || object == nullptr || petilil::commandable::event::max <= type, return);

        if (const petilil::commandable::callback::function func = callbackSet.functions[type]; func != nullptr) func(*object, type, *o, e);
    }

    inline const commandable * petilil::commandable::subscription::objectGet(void) const {
        return object;
    }

    inline commandable * petilil::commandable::subscription::objectGet(void) {
        return object;
    }

    inline int petilil::commandable::subscription::executeCnt(void) const {
        return count;
    }

    inline void petilil::commandable::subscription::raise(petilil::event::link * o, pokemon::faint * e) {
        pokemon_training_check(o->subscriptionGet() != this, return);

        petilil::commandable::link * node = pokemon::cast<petilil::commandable::link * >(o);

        callbackOn(node, o->identifierGet(), e);

        if (e != nullptr) subscriptionOn(petilil::commandable::subscription::state::type::chk, e->clone());
    }



    inline petilil::commandable::subscription::subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet) : petilil::event::subscription(properties), count(declaration::zero), object(object) {
        memcpy(pointof(this->callbackSet), pointof(callbackSet), sizeof(petilil::commandable::subscription::callback::set));
    }

    inline petilil::commandable::subscription::subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::function on) : petilil::event::subscription(properties, reinterpret_cast<petilil::event::subscription::callback::function>(on)), count(declaration::zero), object(object) {
        memcpy(pointof(this->callbackSet), pointof(callbackSet), sizeof(petilil::commandable::subscription::callback::set));
    }

    inline petilil::commandable::subscription::subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::modifier modifiableOn) : petilil::event::subscription(properties, reinterpret_cast<petilil::event::subscription::callback::modifier>(modifiableOn)), count(declaration::zero), object(object) {
        memcpy(pointof(this->callbackSet), pointof(callbackSet), sizeof(petilil::commandable::subscription::callback::set));
    }

    inline petilil::commandable::subscription::subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::function on, petilil::commandable::subscription::callback::modifier modifiableOn)  : petilil::event::subscription(properties, reinterpret_cast<petilil::event::subscription::callback::function>(on), reinterpret_cast<petilil::event::subscription::callback::modifier>(modifiableOn)), count(declaration::zero), object(object) {
        memcpy(pointof(this->callbackSet), pointof(callbackSet), sizeof(petilil::commandable::subscription::callback::set));
    }

    inline petilil::commandable::subscription::subscription(void) : count(declaration::zero), object(nullptr) {
        memset(pointof(this->callbackSet), 0, sizeof(petilil::commandable::subscription::callback::set));
    }

    inline petilil::commandable::subscription::~subscription(void) {
    }

}

#endif // __POKEMONISM_PETILIL_COMMANDABLE_SUBSCRIPTION_HH__