/**
 * @file        pokemon/latios/command.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#include "command.hh"

#include "engine.hh"

namespace pokemon { namespace latios {

    const command::event::handlerSet    command::event::printableCallbackSet = {
        command::event::printableOn,
        command::event::printableOn,
        command::event::printableOn,
        command::event::printableOn,
        command::event::printableOn
    };

    void engineCancelFunc(external::engine & o) {

    }

    int command::event::engineOff(command * o, uint32 type, external::command::event * event, primitivable::object * result) {
        pokemon::latios::engine::off(engineCancelFunc);
        return declaration::success;
    }

    int command::event::printableOn(command * o, uint32 type, external::command::event * event, primitivable::object * result) {
        printf("command event type => %d\n", type);
        return declaration::success;
    }

} }