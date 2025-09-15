/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#include "applicationable.hh"

namespace pokemonism {

    applicationable * applicationable::singleton = nullptr;

    int run(applicationable * o) {
        if (o != nullptr) {
            const int ret = o->run();

            delete o;

            return ret;
        }

        return declaration::fail;
    }

}