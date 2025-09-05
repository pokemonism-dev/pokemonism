/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_EVENT_ENVELOPE_HH__
#define   __POKEMONISM_EVENT_ENVELOPE_HH__

#include <pokemonism/sdk/event.hh>

namespace pokemonism::sdk {

    inline const event::exception * event::envelope::exceptionGet(void) const {
        return exception;
    }

    inline event::subscription * event::envelope::subscriptionGet(void) const {
        return container;
    }

    inline event::envelope::envelope(event::subscription * container, event::exception * exception) : exception(nullptr), container(container) {
        pokemon_develop_check(container == nullptr, (void)(0));
    }

    inline event::envelope::envelope(void) : exception(nullptr), container(nullptr) {

    }

    inline event::envelope::~envelope(void) {
        exception = allocator::del(exception);
    }

}

#endif // __POKEMONISM_EVENT_ENVELOPE_HH__