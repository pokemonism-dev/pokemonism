/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_FIFO_HH__
#define   __POKEMONISM_SDK_INTERFACE_FIFO_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    class fifo {
    public:     fifo(void) {}
    public:     virtual ~fifo(void) {}
    public:     fifo(const interface::fifo & o) = delete;
    public:     fifo(interface::fifo && o) noexcept = delete;
    public:     interface::fifo & operator=(const interface::fifo & o) = delete;
    public:     interface::fifo & operator=(interface::fifo && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_FIFO_HH__