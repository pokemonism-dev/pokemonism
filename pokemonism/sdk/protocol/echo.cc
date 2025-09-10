/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "echo.hh"

namespace pokemonism::protocol {

    echo::deserializer & echo::in = echo::deserializer::get();
    echo::serializer & echo::out = echo::serializer::get();

    echo & echo::get(void) {
        static echo singleton;

        return singleton;
    }



}