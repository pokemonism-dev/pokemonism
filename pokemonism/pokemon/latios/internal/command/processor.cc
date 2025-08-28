/**
 * @file        pokemon/latios/internal/command/processor.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#include "processor.hh"
#include "generator.hh"

#include "event.hh"

namespace pokemon { namespace latios { namespace internal { namespace command {

    int processor::execute(command::subscription * subscription, uint32 type, command::event * event) {
        if (latios::command * object = subscription->objectGet(); object != nullptr) {
            int ret = fail;
            try {
                ret = subscription->on(latios::command::event::exe, event, (*object)(), nullptr);
            } catch (pokemon::exception & e) {
                ret = subscription->on(latios::command::event::exe, event, nullptr, pointof(e));
            }

            if (subscription->complete()) {
                command::generator * generator = dynamic_cast<command::generator *>(subscription->generatorGet());

                generator->post(subscription, latios::command::event::del);
            }

            return ret;
        }

        return declaration::fail;
    }

    int processor::on(command::subscription * subscription, const uint32 type, command::event * event) {
        pokemon::exception * e = event->exceptionGet();
        return subscription->on(type, event, (e != nullptr ? primitivable::object::gen(fail) : primitivable::object::gen(success)), e);
    }

} } } }