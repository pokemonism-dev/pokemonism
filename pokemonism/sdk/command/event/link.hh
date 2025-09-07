/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMAND_EVENT_LINK_HH__
#define   __POKEMONISM_SDK_COMMAND_EVENT_LINK_HH__

#include <pokemonism/sdk/command/event.hh>

namespace pokemonism::sdk {

    inline command::event::link::link(void) {

    }

    inline command::event::link::link(pokemonism::sdk::event::exception * exception) : command::event::envelope(exception) {

    }

    inline command::event::link::link(command::event::subscription * container) {
        subscriptionReg(container);
    }

    inline command::event::link::~link(void) {

    }

}

#endif // __POKEMONISM_SDK_COMMAND_EVENT_LINK_HH__