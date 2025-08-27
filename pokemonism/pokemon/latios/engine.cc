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

    engine::engine(void) : queue() {
    }

    engine::~engine(void) {

    }

    // class engine {
    // protected:  queue queue;
    // public:     engine(void);
    // public:     virtual ~engine(void);
    // public:     engine(engine & o);
    // public:     engine(engine && o) noexcept;
    // public:     engine & operator=(engine & o);
    // public:     engine & operator=(engine && o) noexcept;
    // };

} }