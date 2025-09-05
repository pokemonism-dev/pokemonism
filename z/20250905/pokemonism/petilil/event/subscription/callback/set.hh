/**
 * @file            pokemonism/petilil/event/subscription/callback/set.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_EVENT_SUBSCRIPTION_CALLBACK_SET_HH__
#define   __POKEMONISM_PETILIL_EVENT_SUBSCRIPTION_CALLBACK_SET_HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/petilil.hh>

namespace pokemonism {
    inline petilil::event::subscription::callback::set::set(void) : on(nullptr), rel(nullptr) {

    }

    inline petilil::event::subscription::callback::set::set(petilil::event::subscription::callback::function on) : on(on), rel(nullptr) {

    }

    inline petilil::event::subscription::callback::set::set(petilil::event::subscription::callback::modifier rel) : on(nullptr), rel(rel) {

    }

    inline petilil::event::subscription::callback::set::set(petilil::event::subscription::callback::function on, petilil::event::subscription::callback::modifier rel) : on(on), rel(rel) {

    }

    inline petilil::event::subscription::callback::set::~set(void) {
        on = nullptr;
        rel = nullptr;
    }
}

#endif // __POKEMONISM_PETILIL_EVENT_SUBSCRIPTION_CALLBACK_SET_HH__