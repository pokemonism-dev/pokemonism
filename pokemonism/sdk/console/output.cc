/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#include "output.hh"

namespace pokemonism::sdk {

    console::output & console::output::get(void) {
        static console::output singleton;

        return singleton;
    }

    console::output::output(void) : generic::descriptor<interface::input::stream<pokemonism::sdk::stream::output<generic::descriptorable::unix<>>>>(STDOUT_FILENO, interface::descriptor::property::console::output){

    }

    console::output::~output(void) {
        value = declaration::invalid;
    }

    long console::output::operator() (char c) {
        pokemonism::sdk::stream * node = out->streamGet(1);

        node->cat(c, 1);
        node->stateSet(pokemonism::sdk::stream::state::process::begin);

        return write();
    }

    long console::output::operator()(const char * s) {
        const unsigned long n = strlen(s);

        if (n > 0) {
            pokemonism::sdk::stream * node = out->streamGet(n);
            node->cat(reinterpret_cast<const unsigned char *>(s), n);
            node->stateSet(pokemonism::sdk::stream::state::process::begin);
        }

        return write();
    }

}