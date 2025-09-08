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

namespace pokemonism::sdk {

    class protocol::transmission::control : public protocol {
    public:     class socket;
    public:     control(void) {}
    public:     ~control(void) override {}
    public:     control(const protocol::transmission::control & o) = delete;
    public:     control(protocol::transmission::control && o) noexcept = delete;
    public:     protocol::transmission::control & operator=(const protocol::transmission::control & o) = delete;
    public:     protocol::transmission::control & operator=(protocol::transmission::control && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_PROTOCOL_TRANSMISSION_CONTROL_HH__