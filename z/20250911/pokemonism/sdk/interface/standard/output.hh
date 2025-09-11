/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_STANDARD_OUTPUT_HH__
#define   __POKEMONISM_INTERFACE_STANDARD_OUTPUT_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface::standard {

    class output : public interface::descriptor {
    public:     output(void) {}
    public:     ~output(void) override {}
    public:     output(const interface::standard::output & o) = delete;
    public:     output(interface::standard::output && o) noexcept = delete;
    public:     interface::standard::output & operator=(const interface::standard::output & o) = delete;
    public:     interface::standard::output & operator=(interface::standard::output && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_INTERFACE_STANDARD_OUTPUT_HH__