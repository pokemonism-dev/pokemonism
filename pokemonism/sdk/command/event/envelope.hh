/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMAND_EVENT_ENVELOPE_HH__
#define   __POKEMONISM_SDK_COMMAND_EVENT_ENVELOPE_HH__

#include <pokemonism/sdk/command/event.hh>

namespace pokemonism::sdk {


    inline primitivable * command::event::envelope::messagePop(void) {
        primitivable * message = output;

        output = nullptr;
        return message;
    }

    inline command::event::envelope::envelope(command::event::subscription * container, pokemonism::sdk::event::exception * exception) : pokemonism::sdk::event::envelope(container, exception), output(nullptr) {

    }

    inline command::event::envelope::envelope(void) : output(nullptr) {

    }

    command::event::envelope::~envelope(void) {
        pokemon_develop_exit_check(output != nullptr, return);

        // ### 20250906 PRIMITIVABLE 타입의 DELETE 는 아무것도 수행되지 않게 막을 수 있나?

    }

}

#endif // __POKEMONISM_SDK_COMMAND_EVENT_ENVELOPE_HH__