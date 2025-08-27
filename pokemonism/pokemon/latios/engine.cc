/**
 * @file        pokemon/latios/engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include "engine.hh"

namespace pokemon { namespace latios {

    engine & engine::get(void) {
        static engine internal;
        return internal;
    }

    const engine & engine::singleton = engine::get();

    engine::engine(void) {
    }

    engine::~engine(void) {

    }

} }