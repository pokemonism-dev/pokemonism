/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_PROTOCOL_TRANSMISSION_CONTROL_HH__
#define   __POKEMONISM_SDK_PROTOCOL_TRANSMISSION_CONTROL_HH__

#include <pokemonism/sdk/protocol/transmission.hh>

namespace pokemonism::sdk::protocol {

    class transmission::control : public interface::protocol {
    public:     class socket;
    public:     control(void) {}
    public:     ~control(void) override {}
    public:     control(const pokemonism::sdk::protocol::transmission::control & o) = delete;
    public:     control(pokemonism::sdk::protocol::transmission::control && o) noexcept = delete;
    public:     pokemonism::sdk::protocol::transmission::control & operator=(const pokemonism::sdk::protocol::transmission::control & o) = delete;
    public:     pokemonism::sdk::protocol::transmission::control & operator=(pokemonism::sdk::protocol::transmission::control && o) noexcept = delete;
    };

}

#include <pokemonism/sdk/protocol/transmission/control/socket.hh>

#endif // __POKEMONISM_SDK_PROTOCOL_TRANSMISSION_CONTROL_HH__