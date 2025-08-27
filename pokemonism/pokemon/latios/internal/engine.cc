/**
 * @file        pokemon/latios/internal/engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include "engine.hh"

namespace pokemon { namespace latios { namespace internal {

    engine & engine::get(void) {
        static engine o;
        return o;
    }

} } }
