/**
 * @file            pokemonism/ralts/kirlia/gardevoir/subscription.cc
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#include "node.hh"
#include "subscription.hh"

namespace pokemonism {
    namespace gardevoir {

        gardevoir::subscription * subscription::rem(gardevoir::subscription * o) {
            pokemon_develop_check(o == nullptr, return nullptr);

            if (o->container != nullptr) o->container->del(o);

            return o;
        }

        // ReSharper disable once CppDFAConstantFunctionResult
        gardevoir::node * subscription::add(gardevoir::node * node) {
            pokemon_develop_check(node == nullptr || node->container != nullptr, return node);

            collection::add(this, node);

            return nullptr;
        }

        gardevoir::node * subscription::del(gardevoir::node * node) {
            pokemon_develop_check(node == nullptr || node->container != this, return node);

            collection::del(this, node);

            return node;
        }

        void subscription::clear(void) {
            collection::clear(this, gardevoir::node::rem);
        }

    }
}
