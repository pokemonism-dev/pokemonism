/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_SESSION_HH__
#define   __POKEMONISM_SDK_INTERFACE_SESSION_HH__

#include <pokemonism/sdk/interface/channel.hh>

namespace pokemonism::sdk::interface {

    class session : public channel {
    public:     session(void) {}
    public:     ~session(void) override {}
    public:     session(const session & o) = delete;
    public:     session(session && o) noexcept = delete;
    public:     session & operator=(const session & o) = delete;
    public:     session & operator=(session && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_SESSION_HH__