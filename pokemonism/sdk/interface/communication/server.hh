/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMUNICATION_SERVER_HH__
#define   __POKEMONISM_SDK_COMMUNICATION_SERVER_HH__

#include <pokemonism/sdk/interface/communicator.hh>

namespace pokemonism::sdk::interface::communication {

    class server : public interface::communicator {
    public:     server(void) {}
    public:     ~server(void) override {}
    public:     server(const interface::communication::server & o) = delete;
    public:     server(interface::communication::server && o) noexcept = delete;
    public:     interface::communication::server & operator=(const interface::communication::server & o) = delete;
    public:     interface::communication::server & operator=(interface::communication::server && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COMMUNICATION_SERVER_HH__