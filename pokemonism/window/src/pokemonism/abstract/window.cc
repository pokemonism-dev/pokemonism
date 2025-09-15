/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */


#include "window.hh"

namespace pokemonism::abstract {

    window::~window(void) {
        if (container != nullptr) container->del(this);

        if (adapter != nullptr) {
            adapter->close();
            delete adapter;
            adapter = nullptr;
        }
    }

}