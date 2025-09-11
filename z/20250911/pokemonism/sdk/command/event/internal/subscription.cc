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

    command::event::internal::subscription::~subscription(void) {
        properties = properties & (~(command::event::subscription::property::release_on_del));
        clear();
        containerDel();

        status = (status & (~command::event::subscription::state::gen));
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        stateOn(command::event::subscription::state::type::rel);
    }

}