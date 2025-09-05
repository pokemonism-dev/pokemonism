/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_EVENT_HH__
#define   __POKEMONISM_PETILIL_EVENT_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {

    inline petilil::event * petilil::event::dispatch(petilil::event * event) {
        pokemon_training_check(event == nullptr, return event);

        if (event->on() <= declaration::success) event = allocator::del(event);

        return event;
    }

    unsigned int petilil::event::identifierGet(void) const {
        return identifier;
    }

    inline int petilil::event::on(void) {
        pokemon_training_check(node == nullptr, return declaration::fail);

        return node->on();
    }

    inline petilil::event::event(unsigned int identifier, petilil::event::link * node) : container(nullptr), prev(nullptr), next(nullptr), node(node), identifier(identifier) {
        pokemon_training_check(node == nullptr, (void)(0));

        node->event = this;
    }

    inline petilil::event::event(void) : container(nullptr), prev(nullptr), next(nullptr), node(nullptr), identifier(declaration::invalid) {

    }

    inline petilil::event::~event(void) {
        petilil::event::rem(this);
    }

}

#endif // __POKEMONISM_PETILIL_EVENT_HH__