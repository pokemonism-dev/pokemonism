/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "session.hh"

#include "server.hh"

namespace pokemonism::sdk::interface {

    session::~session(void) {
        if (container != nullptr) container->del(this);
    }

}