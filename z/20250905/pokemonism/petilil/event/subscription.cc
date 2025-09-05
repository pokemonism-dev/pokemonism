/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */


#include "subscription.hh"

namespace pokemonism {

    // ReSharper disable once CppDFAConstantFunctionResult
    petilil::event::link * petilil::event::subscription::add(petilil::event::link * o) {
        pokemon_training_check(o == nullptr || o->container != nullptr, return o);

        collection::add(this, o);

        return nullptr;
    }

    petilil::event::link * petilil::event::subscription::del(petilil::event::link * o) {
        pokemon_training_check(o == nullptr || o->container != this, return o);

        collection::del(this, o);

        return o;
    }

    void petilil::event::subscription::clear(void) {
        collection::clear(this);
    }

}