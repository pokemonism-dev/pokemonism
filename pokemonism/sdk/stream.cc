/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */


#include "stream.hh"

namespace pokemonism::sdk {

    unsigned long stream::pageGet(void) const { return container != nullptr ? container->pageGet() : stream::buffer::defaultPage; }

    stream::stream(stream::buffer * container) : container(nullptr), prev(nullptr), next(nullptr) {
        pokemon_develop_check(container == nullptr, return);

        container->add(this);
    }

    stream::~stream(void) {
        if (container != nullptr) container->del(this);
    }


}