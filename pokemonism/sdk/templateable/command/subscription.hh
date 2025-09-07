/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_SUBSCRIPTION_HH__
#define   __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_SUBSCRIPTION_HH__

#include <pokemonism/sdk/templateable/command.hh>

namespace pokemonism::sdk::templateable {

    template <class commandable, typename outputable>
    inline void command::subscription<commandable, outputable>::callbackOn(unsigned int type, const pokemonism::sdk::event::exception * problem) {
        command::envelope<commandable, outputable> envelope(this);

        callbackOn(type, envelope, problem);
    }

}

#endif // __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_SUBSCRIPTION_HH__