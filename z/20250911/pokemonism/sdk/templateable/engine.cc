/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#include "engine.hh"

#include "command.hh"

namespace pokemonism::sdk::templateable {

    int engine::on(bootstrapper bootstrap) {
        if (queue == nullptr) {
            if (bootstrap != nullptr) bootstrap(*this, pointof(queue), generator);

            queue = new event::queue();
            generator.command = new templateable::command::event::generator(this);

            return declaration::success;
        }

        return declaration::fail;
    }

}