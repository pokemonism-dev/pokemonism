/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "generator.hh"

namespace pokemonism::sdk {

    // ReSharper disable once CppDFAConstantFunctionResult
    event::subscription * event::generator::add(event::subscription * subscription) {
        pokemon_develop_check(subscription == nullptr || subscription->container != nullptr, return subscription);

        collection::add(this, subscription);

        subscription->on(event::subscription::state::type::add);

        return nullptr;
    }

    event::subscription * event::generator::del(event::subscription * subscription) {
        pokemon_develop_check(subscription == nullptr || subscription->container != this, return subscription);

        subscription->on(event::subscription::state::type::del);

        collection::del(this, subscription);

        if (subscription->propertyChk(event::subscription::property::release_on_del)) {
            queue.add(new event::subscription::releaser(subscription));
        }

        return subscription;
    }

    runnable::queue::node * event::generator::add(runnable::queue::node * f) {
        return queue.add(f);
    }

    runnable::queue::node * event::generator::del(runnable::queue::node * f) {
        return queue.del(f);
    }

    void event::generator::clear(void) {
        while (head != nullptr) {
            if (head->propertyChk(event::subscription::property::release_on_del)) delete del(head);
        }

        queue(declaration::infinite);
    }

}