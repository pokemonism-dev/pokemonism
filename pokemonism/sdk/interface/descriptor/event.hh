/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_EVENT_HH__
#define   __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_EVENT_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    class descriptor::event {
    public:     constexpr static unsigned int open = 0;
    public:     constexpr static unsigned int read = 0;
    public:     constexpr static unsigned int write = 0;
    public:     constexpr static unsigned int close = 0;
    };


}

#endif // __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_EVENT_HH__