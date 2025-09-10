/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_CHANNEL_HH__
#define   __POKEMONISM_SDK_INTERFACE_CHANNEL_HH__

#include <pokemonism/sdk/interface/communicator.hh>

namespace pokemonism::sdk::interface {

    class channel : public communicator {
    public:     channel(void) {}
    public:     ~channel(void) override {}
    public:     channel(const channel & o) = delete;
    public:     channel(channel && o) noexcept = delete;
    public:     channel & operator=(const channel & o) = delete;
    public:     channel & operator=(channel && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_CHANNEL_HH__