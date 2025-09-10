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
#include <pokemonism/sdk/generic/socketable/unix.hh>

using namespace pokemonism::sdk;

int main(int argc, char ** argv) {

    generic::descriptor<stream::input<stream::output<generic::descriptorable::unix<>>>> o;

    // generic::descriptorable::unix<stream::input<stream::output<generic::descriptor<>>>> o;
    // generic::descriptorable::unix<interface::input::stream<stream::output<generic::descriptor<>>>> o1;
    // generic::descriptorable::unix<stream::input<interface::output::stream<generic::descriptor<>>>> o2;

    // generic::socketable::unix<generic::descriptorable::unix<


    return 0;
}
