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

        pokemon::interface::terminatable<1, wattrel::engine *> engine::T;
        int engine::run(void) {
            while (terminator == nullptr) {
                queue->on(declaration::infinite);

                generator.command->on();
            }
            terminator.terminate(this);

            return declaration::success;
        }

        void engine::on(bootstrapper bootstrap) {
            T.func[0] = t800;
            T.basic = t800;
            if (bootstrap) bootstrap(referenceof(this));

            if (queue == nullptr) queue = new wattrel::queue();
            if (generator.command == nullptr) generator.command = new wattrel::command::generator(this);
        }

        void engine::off(engine::cancellation executor) {
            if (terminator == nullptr && executor == nullptr) {
                terminator = (T-800);
            } else if (terminator == nullptr) {
                terminator = executor;
            }
        }

        pokemon::event::subscription * engine::reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n) {
            return generator.command->reg(target, properties, callbacks, n);
        }

        engine::engine(void) : queue(nullptr), terminator(nullptr), generator() {

        }

        engine::~engine(void) {

        }

    }
}