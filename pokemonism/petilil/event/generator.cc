/**
 * @file            pokemonism/petilil/event/generator.cc
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */


#include "generator.hh"

namespace pokemonism {

    petilil::event::subscription * petilil::event::generator::add(petilil::event::subscription * o) {
        pokemon_training_check(o == nullptr || o->container != nullptr, return o);

        collection::add(this, o, *this);

        return nullptr;
    }

    petilil::event::subscription * petilil::event::generator::del(petilil::event::subscription * o) {
        pokemon_training_check(o == nullptr || o->container != this, return o);

        collection::add(this, o, *this);

        return o;
    }

    void petilil::event::generator::clear(void) {
        while (head != nullptr) petilil::event::generator::subscriptionRel(collection::del(this, head, *this));
    }

}