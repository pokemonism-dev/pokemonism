/**
 * @file        pokemon/latios/engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 28, 2025
 */

#include "engine.hh"

#include "internal/engine.hh"

namespace pokemon { namespace latios {

    // static internal::engine o;
    static internal::engine * o = nullptr;

    const char * engine::tag(void) {
        return o != nullptr ? o->tag() : nullptr;
    }

    external::command::subscription * engine::reg(command * command, uint32 properties, command::event::listener (*on)[command::event::max]) {
        return o != nullptr ? o->reg(command, properties, on) : nullptr;
    }

    external::engine & engine::on(void (*bootstrap)(external::engine &)) {
        if (o == nullptr) {
            // ### 20250828 | ATEXIT 에 등록하자.
            o = new internal::engine();

            if (bootstrap != nullptr) bootstrap(valueof(o));

            o->on();
        }

        return *o;
    }

    void engine::off(void (*func)(external::engine &)) {
        if (o != nullptr) o->off(func);
    }

    int engine::run(void) {
        if (o == nullptr) {
            o = new internal::engine();
            o->on();
        }

        return o->run();
    }

} }
