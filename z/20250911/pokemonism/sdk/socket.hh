/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_SDK_SOCKET_HH__
#define   __POKEMONISM_SDK_SOCKET_HH__

#include <pokemonism/sdk/generic/socket.hh>
#include <pokemonism/sdk/generic/socketable/unix.hh>
#include <pokemonism/sdk/interface/socket.hh>
#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/protocol/transmission/control/protocol.hh>

namespace pokemonism::sdk {

    // Socket


    template <class tag = interface::socket::tag>
    class socket {

    };

    template <> class socket<pokemonism::protocol::transmission::control::protocol::socket::session> : public generic::socket<stream::input<stream::output<generic::socketable::unix<pokemonism::protocol::transmission::control::protocol::socket::session>>>> {

    };
}

#endif // __POKEMONISM_SDK_SOCKET_HH__