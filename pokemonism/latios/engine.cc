/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "engine.hh"

#include <pokemonism/ralts/kirlia/engine.hh>

#include <pokemonism/pokemon/exception.hh>

namespace pokemonism {
    namespace latios {

        // kirlia::engine

        int engine::on(void) {
            return kirlia::engine::on();
        }

        void engine::off(void (*terminator)(void)) {
            return kirlia::engine::off(terminator);
        }

        int engine::run(void) {
            return kirlia::engine::run();
        }

        engine::engine(void) {

        }

        engine::~engine(void) {

        }
    }
}