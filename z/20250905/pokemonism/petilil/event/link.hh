/**
 * @file            pokemonism/petilil/event/link.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_EVENT_LINK_HH__
#define   __POKEMONISM_PETILIL_EVENT_LINK_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {

    inline unsigned int petilil::event::link::identifierGet(void) const {
        pokemon_training_check(event == nullptr, return declaration::fail);

        return event->identifierGet();
    }

    inline void petilil::event::link::returnSet(int v) {
        ret = v;
    }

    inline int petilil::event::link::on(void) {
        pokemon_training_check(container == nullptr || event == nullptr, return declaration::fail);

        return container->processOn(this);
    }

    inline petilil::event::link::link(petilil::event::subscription * subscription) : prev(nullptr), next(nullptr), event(nullptr) {
        pokemon_training_check(subscription == nullptr, return);

        subscription->add(this);
    }

    inline petilil::event::link::link(void) : prev(nullptr), next(nullptr), event(nullptr) {

    }

    inline petilil::event::link::~link(void) {
        petilil::event::link::rem(this);
    }

}

#endif // __POKEMONISM_PETILIL_EVENT_LINK_HH__