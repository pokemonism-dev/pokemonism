/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_SDK_EVENT_LINK_HH__
#define   __POKEMONISM_SDK_EVENT_LINK_HH__

#include <pokemonism/sdk/event.hh>

namespace pokemonism::sdk {

    inline unsigned int event::link::identifierGet(void) const {
        pokemon_develop_check(e == nullptr, return declaration::invalid);

        return e->identifier;
    }

    inline event::exception * event::link::exceptionSet(event::exception * problem) {
        if (exception == nullptr) {
            exception = problem;

            return nullptr;
        }

        return problem;
    }

    inline int event::link::on(void) {
        pokemon_develop_check(container == nullptr, return declaration::fail);

        return container->processOn(this);
    }

    inline void event::link::raise(event::exception * exception) {
        pokemon_develop_check(exception == nullptr, return);

        container->raise(this, exception);

        if (this->exception != nullptr) {
            delete exception;
            return;
        }

        this->exception = exception;
    }

    inline void event::link::containerReg(event::subscription * o) {
        pokemon_develop_check(container != nullptr, return);

        o->add(this);
    }

    inline event::link::link(event::exception * exception) : event::envelope(exception), prev(nullptr), next(nullptr), e(nullptr) {

    }

    inline event::link::link(event::subscription * container, event::exception * exception) : event::envelope(exception), prev(nullptr), next(nullptr), e(nullptr) {
        pokemon_develop_check(container == nullptr, return);

        container->add(this);
    }

    inline event::link::link(event::subscription * container) : prev(nullptr), next(nullptr), e(nullptr) {
        pokemon_develop_check(container == nullptr, return);

        container->add(this);
    }

    inline event::link::link(void) : prev(nullptr), next(nullptr), e(nullptr) {

    }

    inline event::link::~link(void) {
        event::link::rem(this);
    }

}

#endif // __POKEMONISM_SDK_EVENT_LINK_HH__