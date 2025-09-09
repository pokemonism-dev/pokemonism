/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#include <pokemonism/sdk/input.hh>
#include <pokemonism/sdk/output.hh>
#include <pokemonism/sdk/generic/descriptor.hh>
#include <pokemonism/sdk/generic/socket.hh>
#include <pokemonism/sdk/input/stream.hh>
#include <pokemonism/sdk/output/stream.hh>

using namespace pokemonism::sdk;

int main(int argc, char ** argv) {
    generic::descriptor<input::stream<output::stream<descriptorable::unix<interface::descriptor>>>> descriptor;
    generic::socket<input::stream<output::stream<socketable::unix>>> socket;

    return 0;
}
