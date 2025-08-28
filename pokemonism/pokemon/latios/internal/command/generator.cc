/**
 * @file        pokemon/latios/internal/command/generator.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 28, 2025
 */

#include "generator.hh"

#include "event.hh"
#include "processor.hh"
#include "subscription.hh"

namespace pokemon { namespace latios { namespace internal { namespace command {

    command::event * generator::eventGen(command::subscription * o, const uint32 type) {
        return new command::event(type, new command::subscription::node(o));
    }

    command::event * generator::dispatch(command::subscription * o, const uint32 type) {
        command::event * event = nullptr;
        switch (type) { // NOLINT(*-multiway-paths-covered)
        case latios::command::event::exe:   event = (processor::execute(o, type, nullptr) == command::event::retry && parent != nullptr ? eventGen(o, type) : nullptr);
        }
        if (event != nullptr) parent->dispatch(event);

        return event;
    }

    command::subscription * generator::subscriptionGen(latios::command * command, const  uint32 properties, latios::command::event::listener (*on)[latios::command::event::max]) {
        develop_quick_throw_check(command == nullptr || on == nullptr, exceptional::nullpointer, return nullptr);

        // ReSharper disable CppDFAConstantConditions
        return command != nullptr && on != nullptr ? new command::subscription(command, properties, on) : nullptr;
        // ReSharper restore CppDFAConstantConditions
    }

    command::subscription * generator::reg(command::subscription * o) {
        if (o != nullptr && o->generatorGet() == nullptr) {
            internal::generator::reg(o);
            dispatch(o, latios::command::event::exe);
        }

        return o;
    }

    command::subscription * generator::del(command::subscription * o) {
        if (o != nullptr && o->generatorGet() == this) {
            internal::generator::del(o);
        }
        return o;
    }

} } } }