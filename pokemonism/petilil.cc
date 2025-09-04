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

        // while (clean == nullptr) {
        //     // queue->on();
        // }
        //
        // clean(this);
        return this;
    }

    petilil::petilil(void) : clean(nullptr), engine(nullptr) {
        engine = new petilil::event::engine();
    }


}