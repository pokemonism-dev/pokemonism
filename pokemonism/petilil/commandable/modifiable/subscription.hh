/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_PETILIL_COMMANDABLE_MODIFIABLE_SUBSCRIPTION_HH__
#define   __POKEMONISM_PETILIL_COMMANDABLE_MODIFIABLE_SUBSCRIPTION_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {

    inline pokemonism::commandable * petilil::commandable::modifiable::subscription::objectPop(void) {
        pokemonism::commandable * o = object;
        object = nullptr;
        return o;
    }

    inline petilil::commandable::modifiable::subscription::subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet) : petilil::commandable::subscription(object, properties, callbackSet) {

    }

    inline petilil::commandable::modifiable::subscription::subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on) : petilil::commandable::subscription(object, properties, callbackSet, on) {

    }

    inline petilil::commandable::modifiable::subscription::subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn) : petilil::commandable::subscription(object, properties, callbackSet, modifiableOn) {

    }

    inline petilil::commandable::modifiable::subscription::subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn) : petilil::commandable::subscription(object, properties, callbackSet, on, modifiableOn) {

    }

    inline petilil::commandable::modifiable::subscription::subscription(void) {

    }

    inline petilil::commandable::modifiable::subscription::~subscription(void) {
        // ReSharper disable CppVirtualFunctionCallInsideCtor
        subscriptionOn(petilil::commandable::modifiable::subscription::state::type::rel);
        clear();
        // ReSharper restore CppVirtualFunctionCallInsideCtor
        if (container != nullptr) container->del(this);

        object = ((properties & petilil::commandable::modifiable::subscription::property::release_object_on_rel) ? allocator::del(object) : nullptr);

        count = declaration::zero;
        memset(pointof(callbackSet), 0, sizeof(callbackSet));
    }

}

#endif // __POKEMONISM_PETILIL_COMMANDABLE_MODIFIABLE_SUBSCRIPTION_HH__