/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "subscription.hh"

namespace pokemonism::sdk {

    void event::subscription::raise(event::link * link, event::exception * problem) {
        pokemon_develop_check(link == nullptr || problem == nullptr, return);

        callbackOn(link->identifierGet(), *link, problem);

        if (exception == nullptr) {
            status = status | event::subscription::state::exception;
            exception = problem->clone();

            callbackOn(event::subscription::state::type::chk, exception);
        }
    }

    bool event::subscription::cancel(void) {
        if (finishChk() == false) {
            status = status | event::subscription::state::cancel;

            clear();

            if (container != nullptr) container->del(this);

            return true;
        }

        return false;
    }

    // ReSharper disable once CppDFAConstantFunctionResult
    event::link * event::subscription::add(event::link * link) {
        pokemon_develop_check(link == nullptr || link->container != nullptr, return link);

        collection::add(this, link, *this);

        return nullptr;
    }

    event::link * event::subscription::del(event::link * link) {
        pokemon_develop_check(link == nullptr || link->container != this, return link);

        collection::del(this, link, *this);

        return link;
    }

    void event::subscription::clear(void) {
        collection::clear(this, *this);
    }

}