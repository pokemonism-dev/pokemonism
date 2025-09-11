/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */


#include "subscription.hh"

namespace pokemonism::sdk {

    void event::internal::subscription::stateOn(unsigned int type, const event::exception * problem) {
        pokemon_develop_check(event::internal::subscription::state::type::max <= type, do {
            if (exception == nullptr && problem != nullptr) {
                status = status | event::releasable::subscription::state::exception;
                exception = problem->clone();
            }
            return;
        } while (0));

        if (exception == nullptr && problem != nullptr) {
            status = status | event::releasable::subscription::state::exception;
            exception = problem->clone();
        }

        if (type == event::internal::subscription::state::type::rel) {
            if (stateSet.rel != nullptr) stateSet.rel(*this, type, problem);
        } else if (stateSet.on != nullptr) {
            stateSet.on(*this, type, problem);
        }
    }

}