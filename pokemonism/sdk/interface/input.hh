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

#include <pokemonism.hh>

namespace pokemonism::sdk::interface {

    class input {
    public:     virtual void clear(void) = 0;
    public:     virtual void clean(void) = 0;
    public:     virtual void reset(void) = 0;
    public:     input(void) {}
    public:     virtual ~input(void) {}
    public:     input(const interface::input & o) = delete;
    public:     input(interface::input && o) noexcept = delete;
    public:     interface::input & operator=(const interface::input & o) = delete;
    public:     interface::input & operator=(interface::input && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_INPUT_HH__