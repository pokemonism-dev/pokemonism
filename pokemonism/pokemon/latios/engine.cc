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

    external::command::subscription * engine::reg(command * command, command::event::handler (*on)[command::event::max]) {
        return o != nullptr ? o->reg(command, on) : nullptr;
    }

    external::command::subscription * engine::mod(command * command, const uint32 type, const command::event::handler on) {
        return o != nullptr? o->mod(command, type, on) : nullptr;
    }

    external::engine & engine::on(void (*bootstrap)(external::engine &)) {
        if (o == nullptr) {
            // ### 20250828 | ATEXIT 에 등록하자.
            o = new internal::engine();

            bootstrap(referenceof(o));

            o->on();
        }

        return *o;
    }

    void engine::cancel(void (*func)(external::engine &)) {
        if (o != nullptr) o->cancel(func);
    }

    int engine::run(void) {
        return o != nullptr ? o->run() : fail;
    }

} }
