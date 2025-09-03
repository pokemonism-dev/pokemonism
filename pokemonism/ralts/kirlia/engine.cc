/**
 * @file            pokemonism/ralts/kirlia/engine.cc
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#include <pokemonism/ralts/kirlia/gardevoir/engine.hh>

#include "engine.hh"

namespace pokemonism {
    namespace kirlia {



        kirlia::subscription * engine::reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet) {
            return gardevoir::engine::reg(target, properties, eventSet);
        }

        kirlia::subscription * engine::reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet) {
            return gardevoir::engine::reg(target, properties, eventSet, subscriptionSet);
        }

        int engine::on(void) {
            return gardevoir::engine::on();
        }

        int engine::run(void) {
            return gardevoir::engine::run();
        }

        void engine::off(kirlia::engine::terminator terminator) {
            gardevoir::engine::off(terminator);
        }

        engine::engine(void) {

        }

        engine::~engine(void) {

        }

    }
}