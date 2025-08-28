/**
 * @file        latios/engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#include "engine.hh"

#include "external/engine.hh"
#include "internal/engine.hh"

namespace pokemonism { namespace latios {

    static engine singleton;
    static internal::engine * o = nullptr;

    int engine::on(void (*bootstrap)(pokemonism::latios::external::engine &)) {
        singleton.lock();
        if (o == nullptr) {
            o = new internal::engine();
            if (bootstrap != nullptr) bootstrap(referenceof(o));
        }
        singleton.unlock();
        return pokemonism::success;
    }

    int engine::run(void) {
        return pokemonism::success;
    }

    engine::engine(void) {

    }

    engine::~engine(void) {
        if (o != nullptr) {
            delete o;
        }
    }
} }
