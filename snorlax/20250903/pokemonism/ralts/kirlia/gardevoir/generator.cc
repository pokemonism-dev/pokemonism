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
            pokemon_develop_check(o == nullptr || o->container != nullptr, do {
                if (o != nullptr) o->on(gardevoir::subscription::event::type::reg, new pokemon::exception());
                return o;
            } while (0));

            collection::add(this, o);

            o->on(gardevoir::subscription::event::type::reg);

            return nullptr;
        }

        gardevoir::subscription * generator::del(gardevoir::subscription * o) {
            pokemon_develop_check(o == nullptr || o->container != this, do {
                if (o != nullptr) o->on(gardevoir::subscription::event::type::del, new pokemon::exception());
                return o;
            } while (0));

            o->on(gardevoir::subscription::event::type::del);

            collection::del(this, o);

            if (o->properties & kirlia::subscription::property::release_on_del) queue.add(new gardevoir::subscription::function::rel(o));

            return o;
        }
    }
}