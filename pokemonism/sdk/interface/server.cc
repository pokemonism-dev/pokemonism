/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "server.hh"

#include "session.hh"
#include "../exception.hh"

namespace pokemonism::sdk::interface {

    session * server::add(session * node) {
        pokemon_develop_check(node == nullptr || node->container != nullptr, return node);

        collection::add(this, node, *this);

        return nullptr;
    }

    session * server::del(session * node) {
        pokemon_develop_check(node == nullptr || node->container != this, return node);

        collection::del(this, node, *this);

        return node;
    }

    server::~server(void) {
        collection::clear(this, *this);
    }

}
