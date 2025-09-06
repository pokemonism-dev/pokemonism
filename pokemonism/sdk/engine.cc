/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#include "engine.hh"

namespace pokemonism::sdk {

    static inline void terminate(engine & o) {

    }

    engine::engine(void) : cancel(nullptr), queue(nullptr) {

    }

    engine::~engine(void) {
        if (generator.command != nullptr) generator.command = allocator::del(generator.command);
        if (queue != nullptr) queue = allocator::del(queue);
        cancel = nullptr;
    }

    int engine::on(bootstrapper bootstrap) {
        if (queue == nullptr) {
            if (bootstrap != nullptr) bootstrap(*this);

            if (queue == nullptr) queue = new event::queue();
            if (generator.command == nullptr) generator.command = new command::event::generator(this);
        }

        return declaration::fail;
    }

    void engine::off(terminator f) {
        if (queue != nullptr) {
            cancel = (f == nullptr ? terminate : f);
        }
    }

    int engine::run(void) {
        if (queue != nullptr) {
            while (cancel == nullptr) {
                queue->on(queue->sizeGet());

                generator.command->on(generator.command->queue.sizeGet());
            }

            cancel(*this);

            queue->on();

            generator.command = allocator::del(generator.command);

            queue = allocator::del(queue);
        }

        return declaration::fail;
    }

}