/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */


#include "petilil.hh"

namespace pokemonism {

    static petilil * singleton = nullptr;

    petilil * petilil::go(void) {
        if (singleton == nullptr) {
            // ### 20250904 | TERMINATOR
            return singleton = new petilil();
        }
        return singleton;
    }

    petilil * petilil::start(void) {
        if (engine == nullptr) {
            engine = new petilil::event::engine();

            engine->on();
        }

        return nullptr;
    }

    int petilil::fight(void) {
        pokemon_training_check(engine == nullptr, return pokemon::battle::result::lose);

        return engine->run();
    }

    petilil::petilil(void) : clean(nullptr), engine(nullptr) {

    }


}