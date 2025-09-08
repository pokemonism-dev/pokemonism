/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SOCKET_HH__
#define   __POKEMONISM_SOCKET_HH__

#include <pokemonism/sdk/protocol/transmission/control.hh>

namespace pokemonism::sdk {

    class protocol::transmission::control::socket {
    public:     socket(void) {}
    public:     ~socket(void) {}
    public:     socket(const protocol::transmission::control::socket & o) = delete;
    public:     socket(protocol::transmission::control::socket && o) noexcept = delete;
    public:     protocol::transmission::control::socket & operator=(const protocol::transmission::control::socket & o) = delete;
    public:     protocol::transmission::control::socket & operator=(protocol::transmission::control::socket && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SOCKET_HH__