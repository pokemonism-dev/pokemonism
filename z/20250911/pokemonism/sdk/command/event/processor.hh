/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_PROCESSOR_HH__
#define   __POKEMONISM_PROCESSOR_HH__

#include <pokemonism/sdk/command/event.hh>

namespace pokemonism::sdk {

    inline int command::event::processor::executeOn(command::event::subscription & subscription, unsigned int type, command::event::envelope * envelope) {
        pokemon_develop_check(subscription.object == nullptr || subscription.finishChk() || envelope == nullptr || envelope->output != nullptr, return declaration::fail);

        envelope->output = (*subscription.object)();

        return subscription.executeSet() ? declaration::success : declaration::again;
    }

}

#endif // __POKEMONISM_PROCESSOR_HH__