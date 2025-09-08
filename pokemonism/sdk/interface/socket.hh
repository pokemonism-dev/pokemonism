/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_SOCKET_HH__
#define   __POKEMONISM_SDK_INTERFACE_SOCKET_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    class socket : public interface::descriptor {
    public:     virtual int shutdown(int how) = 0;
    public:     socket(void) {}
    public:     ~socket(void) override {}
    public:     socket(const interface::socket & o) = delete;
    public:     socket(interface::socket && o) noexcept = delete;
    public:     interface::socket & operator=(const interface::socket & o) = delete;
    public:     interface::socket & operator=(interface::socket && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_SOCKET_HH__