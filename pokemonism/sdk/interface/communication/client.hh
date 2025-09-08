/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMUNICATION_CLIENT_HH__
#define   __POKEMONISM_SDK_COMMUNICATION_CLIENT_HH__

#include <pokemonism/sdk/interface/communicator.hh>

namespace pokemonism::sdk::interface::communication {

    class client : public interface::communicator {
    public:     client(void) {}
    public:     ~client(void) override {}
    public:     client(const interface::communication::client & o) = delete;
    public:     client(interface::communication::client && o) noexcept = delete;
    public:     interface::communication::client & operator=(const interface::communication::client & o) = delete;
    public:     interface::communication::client & operator=(interface::communication::client && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COMMUNICATION_CLIENT_HH__