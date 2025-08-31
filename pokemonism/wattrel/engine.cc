/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "engine.hh"

#include <pokemonism/pokemon/exception.hh>


namespace pokemonism {

    namespace wattrel {

        static void t800(engine * o) {}

        int engine::run(void) {
            while (cancel == nullptr) {

            }
            cancel(this);

            return declaration::success;
        }

        void engine::on(bootstrapper bootstrap) {
            if (bootstrap) bootstrap(referenceof(this));
        }

        void engine::off(engine::terminator executor) {
            if (cancel == nullptr && executor == nullptr) cancel = executor;

            cancel = t800;
        }

        pokemon::subscription * engine::reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n) {
            throw exception();
        }

        engine::engine(void) : cancel(nullptr), generator() {

        }

        engine::~engine(void) {

        }

    }
}