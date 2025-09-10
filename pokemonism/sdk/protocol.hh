/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_PROTOCOL_HH__
#define   __POKEMONISM_SDK_PROTOCOL_HH__

#include <pokemonism/sdk/context.hh>

namespace pokemonism::sdk {

    class protocol {
    public:     protocol(void) {}
    public:     virtual ~protocol(void) {}
    public:     protocol(const protocol & o) = delete;
    public:     protocol(protocol && o) noexcept = delete;
    public:     protocol & operator=(const protocol & o) = delete;
    public:     protocol & operator=(protocol && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_PROTOCOL_HH__