/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "serializer.hh"

namespace pokemonism::protocol {

    echo::serializer & echo::serializer::get() {
        static echo::serializer singleton(echo::get());

        return singleton;
    }

    pokemonism::sdk::stream * echo::serializer::serialize(pokemonism::sdk::stream * input, pokemonism::sdk::stream * output) {
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

    pokemonism::sdk::stream * echo::serializer::serialize(const char * format, ...) {
        pokemon_develop_check(format == nullptr || format[0] == 0, return nullptr);

        va_list ap;
        va_start(ap, format);
        pokemonism::sdk::stream * stream = new  pokemonism::sdk::stream(format, ap);
        va_end(ap);

        return stream;
    }

    echo::serializer::serializer(echo & protocol) : protocol(protocol) {

    }

    echo::serializer::~serializer(void) {

    }

}