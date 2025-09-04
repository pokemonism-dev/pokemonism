/**
 * @file            pokemonism/petilil/event/modifiable/subscription.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_EVENT_MODIFIABLE_SUBSCRIPTION_HH__
#define   __POKEMONISM_PETILIL_EVENT_MODIFIABLE_SUBSCRIPTION_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {

    inline petilil::event::modifiable::subscription::subscription(unsigned int properties) : petilil::event::subscription(properties) {

    }

    inline petilil::event::modifiable::subscription::subscription(unsigned int properties, petilil::event::subscription::callback::function on) : petilil::event::subscription(properties, on) {

    }

    inline petilil::event::modifiable::subscription::subscription(unsigned int properties, petilil::event::subscription::callback::modifier modifiableOn) : petilil::event::subscription(properties, modifiableOn) {

    }

    inline petilil::event::modifiable::subscription::subscription(unsigned int properties, petilil::event::subscription::callback::function on, petilil::event::subscription::callback::modifier modifiableOn) : petilil::event::subscription(properties, on, modifiableOn) {

    }

    inline petilil::event::modifiable::subscription::subscription(void) {

    }

    inline petilil::event::modifiable::subscription::~subscription(void) {
    }

}

#endif // __POKEMONISM_PETILIL_EVENT_MODIFIABLE_SUBSCRIPTION_HH__