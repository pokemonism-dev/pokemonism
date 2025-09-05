/**
 * @file            pokemonism/petilil/event/envelope.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_EVENT_ENVELOPE_HH__
#define   __POKEMONISM_PETILIL_EVENT_ENVELOPE_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {

    inline petilil::event::subscription * petilil::event::envelope::subscriptionGet(void) const {
        return container;
    }

    inline const pokemon::faint * petilil::event::envelope::exceptionGet(void) const {
        return exception;
    }

    inline int petilil::event::envelope::returnGet(void) const {
        return ret;
    }

    inline petilil::event::envelope::envelope(petilil::event::subscription * subscription, int ret) : container(subscription), exception(nullptr), ret(ret) {

    }

    inline petilil::event::envelope::envelope(petilil::event::subscription * subscription, int ret, pokemon::faint * exception) : container(subscription), exception(exception), ret(ret) {

    }

    inline petilil::event::envelope::envelope(void) : container(nullptr), exception(nullptr), ret(declaration::none) {

    }

    inline petilil::event::envelope::~envelope(void) {
        exception = allocator::del(exception);
        container = nullptr;
    }

}

#endif // __POKEMONISM_PETILIL_EVENT_ENVELOPE_HH__