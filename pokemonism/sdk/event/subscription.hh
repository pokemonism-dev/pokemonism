/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_SDK_EVENT_SUBSCRIPTION_HH__
#define   __POKEMONISM_SDK_EVENT_SUBSCRIPTION_HH__

#include <pokemonism/sdk/event.hh>

namespace pokemonism::sdk {

    inline bool event::subscription::finishChk(void) const {
        return (status & (event::subscription::state::complete | event::subscription::state::cancel | event::subscription::state::exception)) != declaration::none;
    }

    inline bool event::subscription::propertyChk(unsigned int flag) const {
        return (properties & flag) != declaration::none;
    }

    inline bool event::subscription::completeChk(void) const {
        return (status & event::subscription::state::complete) != declaration::none;
    }

    inline bool event::subscription::cancelChk(void) const {
        return (status & event::subscription::state::cancel) != declaration::none;
    }

    inline bool event::subscription::exceptionChk(void) const {
        return (status & event::subscription::state::exception) != declaration::none;
    }

    inline bool event::subscription::stateChk(unsigned int state) const {
        return (status & state) != declaration::none;
    }

    inline event::subscription::subscription(unsigned int properties) : size(declaration::zero), head(nullptr), tail(nullptr), container(nullptr), prev(nullptr), next(nullptr), properties(properties), status(declaration::none), stateSet(), exception(nullptr) {
        status = status | event::subscription::state::gen;
    }

    inline event::subscription::subscription(unsigned int properties, event::subscription::state::callback::function on) : size(declaration::zero), head(nullptr), tail(nullptr), container(nullptr), prev(nullptr), next(nullptr), properties(properties), status(declaration::none), stateSet(on), exception(nullptr) {
        status = status | event::subscription::state::gen;
    }

    inline event::subscription::subscription(unsigned int properties, event::subscription::state::callback::modifier rel) : size(declaration::zero), head(nullptr), tail(nullptr), container(nullptr), prev(nullptr), next(nullptr), properties(properties), status(declaration::none), stateSet(rel), exception(nullptr) {
        status = status | event::subscription::state::gen;
    }
    inline event::subscription::subscription(unsigned int properties, event::subscription::state::callback::function on, event::subscription::state::callback::modifier rel) : size(declaration::zero), head(nullptr), tail(nullptr), container(nullptr), prev(nullptr), next(nullptr), properties(properties), status(declaration::none), stateSet(on, rel), exception(nullptr) {
        status = status | event::subscription::state::gen;
    }

    inline event::subscription::subscription(void) : size(declaration::zero), head(nullptr), tail(nullptr), container(nullptr), prev(nullptr), next(nullptr), properties(declaration::none), status(declaration::none), stateSet(), exception(nullptr) {
        status = status | event::subscription::state::gen;
    }

    inline event::subscription::~subscription(void) {

    }

}

#endif // __POKEMONISM_SDK_EVENT_SUBSCRIPTION_HH__