/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_SOCKET_HH__
#define   __POKEMONISM_SDK_GENERIC_SOCKET_HH__

#include <pokemonism/sdk/interface/input.hh>
#include <pokemonism/sdk/interface/output.hh>
#include <pokemonism/sdk/interface/socket.hh>
#include <pokemonism/sdk/generic/descriptor.hh>

namespace pokemonism::sdk::generic {

    // template <class inputable = pokemonism::sdk::interface::input, class outputable = pokemonism::sdk::interface::output>
    // class socket : public interface::socket, public generic::descriptor<inputable, outputable> {
    // public:     socket(void) {}
    // public:     ~socket(void) override {}
    // public:     socket(const generic::socket<inputable, outputable> & o) = delete;
    // public:     socket(generic::socket<inputable, outputable> && o) noexcept = delete;
    // public:     generic::socket<inputable, outputable> & operator=(const generic::socket<inputable, outputable> & o) = delete;
    // public:     generic::socket<inputable, outputable> & operator=(generic::socket<inputable, outputable> && o) noexcept = delete;
    // };
}

#endif // __POKEMONISM_SOCKET_HH__