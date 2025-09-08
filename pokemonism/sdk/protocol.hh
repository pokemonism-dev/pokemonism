/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_PROTOCOL_HH__
#define   __POKEMONISM_SDK_PROTOCOL_HH__

#include <pokemonism.hh>

namespace pokemonism::sdk {

    class protocol {
    public:     struct transmission;
    public:     protocol(void) {}
    public:     virtual ~protocol(void) {}
    public:     protocol(protocol & o) = delete;
    public:     protocol(protocol && o) noexcept = delete;
    public:     protocol & operator=(protocol & o) = delete;
    public:     protocol & operator=(protocol && o) noexcept = delete;
    };

}

#include <pokemonism/sdk/protocol/transmission.hh>

#endif // __POKEMONISM_SDK_PROTOCOL_HH__