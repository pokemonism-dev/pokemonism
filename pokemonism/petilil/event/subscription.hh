/**
 * @file            pokemonism/petilil/event/subscription.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_EVENT_SUBSCRIPTION_HH__
#define   __POKEMONISM_PETILIL_EVENT_SUBSCRIPTION_HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/petilil.hh>

namespace pokemonism {

    inline bool petilil::event::subscription::cancel(void) {
        if (finishChk() == false) {
            status = status | petilil::event::subscription::state::cancel;

            clear();

            if (container != nullptr) container->del(this);

            return true;
        }

        return false;
    }

    inline const pokemon::faint * petilil::event::subscription::faintGet(void) const {
        return exception;
    }

    inline unsigned long petilil::event::subscription::eventCnt(void) const {
        return size;
    }

    inline unsigned int petilil::event::subscription::stateChk(unsigned int state) const {
        return status & state;
    }

    inline unsigned int petilil::event::subscription::propertyChk(unsigned int property) const {
        return properties & property;
    }

    inline bool petilil::event::subscription::completeChk(void) const {
        return (status & petilil::event::subscription::state::complete) != declaration::none;
    }

    inline bool petilil::event::subscription::cancelChk(void) const {
        return (status & petilil::event::subscription::state::cancel) != declaration::none;
    }

    inline bool petilil::event::subscription::finishChk(void) const {
        return ((status & (petilil::event::subscription::state::complete | petilil::event::subscription::state::cancel)) != declaration::none) || exception != nullptr;
    }

    inline petilil::event::subscription::subscription(unsigned int properties) : container(nullptr), prev(nullptr), next(nullptr), head(nullptr), tail(nullptr), exception(nullptr), size(declaration::zero), properties(properties), status(declaration::none) {

    }

    inline petilil::event::subscription::subscription(unsigned int properties, petilil::event::subscription::callback::function on) : container(nullptr), prev(nullptr), next(nullptr), head(nullptr), tail(nullptr), exception(nullptr), size(declaration::zero), properties(properties), status(declaration::none), subscriptionSet(on) {

    }

    inline petilil::event::subscription::subscription(unsigned int properties, petilil::event::subscription::callback::modifier modifiableOn) : container(nullptr), prev(nullptr), next(nullptr), head(nullptr), tail(nullptr), exception(nullptr), size(declaration::zero), properties(properties), status(declaration::none), subscriptionSet(modifiableOn) {

    }

    inline petilil::event::subscription::subscription(unsigned int properties, petilil::event::subscription::callback::function on, petilil::event::subscription::callback::modifier modifiableOn) : container(nullptr), prev(nullptr), next(nullptr), head(nullptr), tail(nullptr), exception(nullptr), size(declaration::zero), properties(properties), status(declaration::none), subscriptionSet(on, modifiableOn) {

    }

    inline petilil::event::subscription::subscription(void) : container(nullptr), prev(nullptr), next(nullptr), head(nullptr), tail(nullptr), exception(nullptr), size(declaration::zero), properties(declaration::none), status(declaration::none) {

    }

    inline petilil::event::subscription::~subscription(void) {
    }

}

#endif // __POKEMONISM_PETILIL_EVENT_SUBSCRIPTION_HH__