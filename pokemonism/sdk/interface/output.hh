/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_OUTPUT_HH__
#define   __POKEMONISM_SDK_INTERFACE_OUTPUT_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    class output : public interface::descriptor {
    public:     output(void) {}
    public:     ~output(void) override {}
    public:     output(const interface::output & o) = delete;
    public:     output(interface::output && o) noexcept = delete;
    public:     interface::output & operator=(const interface::output & o) = delete;
    public:     interface::output & operator=(interface::output && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_OUTPUT_HH__