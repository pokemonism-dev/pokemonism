/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/generic/descriptorable/unix.hh>

using namespace pokemonism::sdk;

int main(int argc, char ** argv) {

    generic::descriptorable::unix<stream::input<stream::output<>>> o;

    return 0;
}
