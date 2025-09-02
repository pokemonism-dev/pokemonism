/**
 * @file            pokemonism/ralts/kirlia/gardevoir/generator.cc
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */


#include "generator.hh"

#include "subscription.hh"

namespace pokemonism {
    namespace gardevoir {

        gardevoir::subscription * generator::reg(gardevoir::subscription * o) {
            pokemon_develop_check(o == nullptr || o->container != nullptr, return o);

            collection::add(this, o);

            return nullptr;
        }

        gardevoir::subscription * generator::del(gardevoir::subscription * o) {
            pokemon_develop_check(o == nullptr || o->container != this, return o);

            collection::del(this, o);

            if (o->properties & kirlia::subscription::property::release_on_del) allocator::del(o);

            return o;
        }
    }
}