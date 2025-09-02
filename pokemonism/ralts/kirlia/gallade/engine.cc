/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */


#include "engine.hh"

namespace pokemonism {
    namespace gallade {

        gallade::subscription * engine::reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::set & callback) {
            pokemon_develop_check(target == nullptr, return nullptr);

            // ### 20250902 | IMPLEMENT THIS
            throw pokemon::exception();
        }
    }
}