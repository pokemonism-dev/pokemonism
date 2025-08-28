/**
 * @file        pokemon/latios/internal/command/event.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#include "event.hh"

#include "processor.hh"

#include "../../exception.hh"

namespace pokemon { namespace latios { namespace internal { namespace command {

    int event::on(pokemon::exception * e) {
        if (e != nullptr) return raise(e);

        switch (type()) {
            case latios::command::event::exe:   return processor::execute(subscriptionGet(), no, this);
            default:                            return raise(new pokemon::latios::exception::unsupported::event());
        }
    }

} } } }
