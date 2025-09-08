/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_PROTOCOL_HYPERTEXT_TRANSFER_HH__
#define   __POKEMONISM_SDK_PROTOCOL_HYPERTEXT_TRANSFER_HH__

#include <pokemonism/sdk/protocol/hypertext.hh>

namespace pokemonism::sdk {

    class protocol::hypertext::transfer : public protocol {
    public:     class client;
    public:     transfer(void) {}
    public:     ~transfer(void) override {}
    public:     transfer(const protocol::hypertext::transfer & o) = delete;
    public:     transfer(protocol::hypertext::transfer && o) noexcept = delete;
    public:     protocol::hypertext::transfer & operator=(const protocol::hypertext::transfer & o) = delete;
    public:     protocol::hypertext::transfer & operator=(protocol::hypertext::transfer && o) noexcept = delete;
    };

}

#include <pokemonism/sdk/protocol/hypertext/transfer/client.hh>

#endif // __POKEMONISM_SDK_PROTOCOL_HYPERTEXT_TRANSFER_HH__