/**
 * @file            pokemonism/petilil/event/modifiable/subscription.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */


#include "subscription.hh"

namespace pokemonism {

    void petilil::event::modifiable::subscription::subscriptionOn(unsigned int type, pokemon::faint * e) {
        pokemon_training_check(petilil::event::subscription::state::type::max <= type, do {
            if (e == nullptr) return;
            type = petilil::event::subscription::state::type::chk;
        } while (0));

        if (exception != nullptr) {
            if (type == petilil::event::subscription::state::type::rel) {
                subscriptionSet.rel(*this, type, e);
                allocator::del(e);
                return;
            }
            subscriptionSet.on(*this, type, e);
            allocator::del(e);
            return;
        }

        exception = e;

        if (type == petilil::event::subscription::state::type::rel) {
            subscriptionSet.rel(*this, type, exception);
            return;
        }
        subscriptionSet.on(*this, type, exception);
    }
}
