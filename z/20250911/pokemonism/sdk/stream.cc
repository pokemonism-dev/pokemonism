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

    void stream::stateSet(unsigned int v) {
        if (v & stream::state::process::end) v = v | (stream::state::package::begin | stream::state::package::end | stream::state::publish::begin);

        unsigned int state = (status ^ v) & (~status);
        unsigned int previous = status;

        status = status | state;

        onState(previous, state);
    }

    void stream::unlink(void) {
        if (container != nullptr) container->del(this);
    }

    unsigned long stream::pageGet(void) const {
        return container != nullptr ? container->pageGet() : stream::buffer::defaultPage;
    }

    stream::stream(stream::buffer * container) : container(nullptr), prev(nullptr), next(nullptr) {
        pokemon_develop_check(container == nullptr, return);

        container->add(this);
    }

    stream::~stream(void) {
        if (container != nullptr) container->del(this);
    }

}