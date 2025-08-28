/**
 * @file        pokemon/latios/command.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#include "command.hh"

namespace pokemon { namespace latios {

    const command::event::handlerSet    command::event::printableCallbackSet = {
        command::event::printableOn,
        command::event::printableOn,
        command::event::printableOn,
        command::event::printableOn,
        command::event::printableOn
    };
} }