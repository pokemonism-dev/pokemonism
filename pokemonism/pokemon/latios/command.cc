/**
 * @file        pokemon/latios/command.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#include <pokemon/log.hh>

#include "command.hh"

#include "engine.hh"

namespace pokemon { namespace latios {

    void command::event::function::engine::cancel(external::engine & o) {
        diagnosticLog("engine cancel\n");
    }

    int command::event::function::engine::off(command * o, uint32 type, external::command::event * event, primitivable::object * result, pokemon::exception * e) {
        pokemon::latios::engine::off(command::event::function::engine::cancel);
        return declaration::success;
    }

    // ReSharper disable CppParameterMayBeConstPtrOrRef
    int command::event::function::print(command * o, const uint32 type, external::command::event * event, primitivable::object * result, pokemon::exception * e) {
        diagnosticLog("type => %d, result: %ld\n", type, primitivable::object::to::int64(result));

        return declaration::success;
    }
    // ReSharper restore CppParameterMayBeConstPtrOrRef

} }