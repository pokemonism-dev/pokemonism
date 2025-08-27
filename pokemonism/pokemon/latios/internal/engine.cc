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
    /** STATIC METHOD */
    engine & engine::get(void) {
        static engine o;
        return o;
    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    engine::engine(void) {

    }

    engine::~engine(void) {

    }

    /** METHOD: EXTERNAL::ENGINE */
    // command::subscription * engine::reg(command * command) {
    //     return nullptr;
    // }


} } }
