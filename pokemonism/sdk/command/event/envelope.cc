/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */


#include "envelope.hh"

namespace pokemonism::sdk {

    void command::event::envelope::reset(void) {
        pokemon_develop_exit_check(output != nullptr, output = nullptr);
        exception = allocator::del(exception);
    }

}