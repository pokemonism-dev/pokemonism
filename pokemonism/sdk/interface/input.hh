/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_INPUT_HH__
#define   __POKEMONISM_SDK_INTERFACE_INPUT_HH__

#include <pokemonism/sdk/interface/output.hh>

namespace pokemonism::sdk::interface {

    template <class output = interface::output>
    class input : public output {
    public:     input(void) {}
    public:     virtual ~input(void) {}
    public:     input(const interface::input<output> & o) = delete;
    public:     input(interface::input<output> && o) noexcept = delete;
    public:     interface::input<output> & operator=(const interface::input<output> & o) = delete;
    public:     interface::input<output> & operator=(interface::input<output> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_INPUT_HH__