/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_SDK_PROTOCOL_TRANSMISSION_CONTROL_PROTOCOL_HH__
#define   __POKEMONISM_SDK_PROTOCOL_TRANSMISSION_CONTROL_PROTOCOL_HH__

#include <netinet/in.h>

#include <pokemonism/sdk/interface/socket.hh>

namespace pokemonism::protocol::transmission::control {

    class socket {

    };


    class protocol {
    public:     struct socket;
    };

    struct protocol::socket : public pokemonism::sdk::interface::socket::tag {
    public:     constexpr static int domain = AF_INET;
    public:     constexpr static int type = SOCK_STREAM;
    public:     constexpr static int protocol = IPPROTO_TCP;
    public:     struct server;
    public:     struct client;
    public:     struct session;
    };

    struct protocol::socket::server : public protocol::socket {};
    struct protocol::socket::client : public protocol::socket {};
    struct protocol::socket::session : public protocol::socket {};

}

#endif // __POKEMONISM_SDK_PROTOCOL_TRANSMISSION_CONTROL_PROTOCOL_HH__