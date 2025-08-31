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

        void engine::t800(engine * o) {}

        int engine::run(void) {
            while (cancel == nullptr) {
                queue->on(declaration::infinite);

                generator.command->on();
            }
            cancel(this);

            return declaration::success;
        }

        void engine::on(bootstrapper bootstrap) {
            if (bootstrap) bootstrap(referenceof(this));

            if (queue == nullptr) queue = new wattrel::queue();
            if (generator.command == nullptr) generator.command = new wattrel::command::generator(this);
        }

        void engine::off(engine::terminator executor) {
            if (cancel == nullptr && executor == nullptr) cancel = executor;

            cancel = t800;
        }

        pokemon::subscription * engine::reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n) {
            return generator.command->reg(target, properties, callbacks, n);
        }

        engine::engine(void) : queue(nullptr), cancel(nullptr), generator() {

        }

        engine::~engine(void) {

        }

    }
}