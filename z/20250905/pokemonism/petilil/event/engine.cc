/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "engine.hh"

namespace pokemonism {

    petilil::event::engine::~engine(void) {
        queue = allocator::del(queue);

        generator.command = objectRel(generator.command);
    }

    int petilil::event::engine::on(void) {
        if (queue == nullptr) {
            queue = new petilil::event::queue();
            generator.command = new petilil::commandable::generator(this);
        }

        return declaration::success;
    }

    int petilil::event::engine::run(void) {
        while (cancel == nullptr) {
            queue->on();

            generator.command->on();
        }

        cancel(*this);

        return declaration::success;
    }

    petilil::event::engine::set::~set() {
        command = petilil::event::engine::objectRel(command);
    }

}