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

    petilil * petilil::go(void) {
        // ### 20280904 | PETILIL | MORE CONCEPT
        return new petilil();
    }

    petilil * petilil::start(void) {
        // TODO: IMPLEMENT THIS
        while (clean == nullptr) {
            // queue->on();
        }

        clean(this);
        return this;
    }

    petilil::petilil(void) : clean(nullptr), engine(nullptr) {

    }


}