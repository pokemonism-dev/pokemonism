/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "deserializer.hh"

namespace pokemonism::protocol {

    echo::deserializer & echo::deserializer::get() {
        static echo::deserializer singleton(echo::get());

        return singleton;
    }

    pokemonism::sdk::stream * echo::deserializer::deserialize(pokemonism::sdk::stream * input, pokemonism::sdk::stream * output) {
        pokemon_develop_check(input == nullptr, return output);

        if (input != output) {
            if (output != nullptr) {
                output->cat(*input);

                output->stateSet(pokemonism::sdk::stream::state::prepare::end | pokemonism::sdk::stream::state::process::begin);
                input->clean();

                return output;
            }
        }

        input->unlink();
        input->reset();
        input->stateSet(pokemonism::sdk::stream::state::prepare::end | pokemonism::sdk::stream::state::process::begin);

        return input;
    }

    echo::deserializer::deserializer(echo & protocol) : protocol(protocol) {

    }

    echo::deserializer::~deserializer(void) {

    }

}