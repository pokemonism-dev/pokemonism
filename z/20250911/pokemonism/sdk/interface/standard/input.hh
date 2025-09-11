/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_STANDARD_INPUT_HH__
#define   __POKEMONISM_INTERFACE_STANDARD_INPUT_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface::standard {

    class input : public interface::descriptor {
    public:     input(void) {}
    public:     ~input(void) override {}
    public:     input(const interface::standard::input & o) = delete;
    public:     input(interface::standard::input && o) noexcept = delete;
    public:     interface::standard::input & operator=(const interface::standard::input & o) = delete;
    public:     interface::standard::input & operator=(interface::standard::input && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_INTERFACE_STANDARD_INPUT_HH__