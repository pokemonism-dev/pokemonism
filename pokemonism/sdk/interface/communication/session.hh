/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMUNICATION_SESSION_HH__
#define   __POKEMONISM_SDK_COMMUNICATION_SESSION_HH__

#include <pokemonism/sdk/interface/communicator.hh>

namespace pokemonism::sdk::interface::communication {

    class session : public interface::communicator {
    public:     session(void) {}
    public:     ~session(void) override {}
    public:     session(const interface::communication::session & o) = delete;
    public:     session(interface::communication::session && o) noexcept = delete;
    public:     interface::communication::session & operator=(const interface::communication::session & o) = delete;
    public:     interface::communication::session & operator=(interface::communication::session && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COMMUNICATION_SESSION_HH__