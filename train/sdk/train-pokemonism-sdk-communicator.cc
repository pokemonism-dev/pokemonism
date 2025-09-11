/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#include <cstdio>
#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/generic/descriptorable/unix.hh>
#include <pokemonism/sdk/generic/socketable/unix.hh>
#include <pokemonism/sdk/generic/socket.hh>
#include <pokemonism/sdk/protocol/transmission/control/protocol.hh>

using namespace pokemonism::sdk;
using namespace pokemonism::protocol;


int main(int argc, char ** argv) {

    // transmission::control::socket::session;
    // transmission::control::socket::server;
    // transmission::control::socket::client;

    generic::socket<stream::input<interface::output::stream<generic::socketable::unix<transmission::control::protocol::socket::client>>>> o;

    try {

    } catch (...) {

    }

    return 0;
}
