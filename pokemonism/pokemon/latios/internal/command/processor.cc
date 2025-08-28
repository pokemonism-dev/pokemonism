/**
 * @file        pokemon/latios/internal/command/processor.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#include "processor.hh"

#include "event.hh"

namespace pokemon { namespace latios { namespace internal { namespace command {


    int processor::execute(command::subscription * subscription, uint32 type, command::event * event) {
        if (latios::command * object = subscription->objectGet(); object != nullptr) {
            primitivable::object * result = (*object)();

            return subscription->on(latios::command::event::exe, event, result);
        }

        return declaration::fail;
    }

} } } }