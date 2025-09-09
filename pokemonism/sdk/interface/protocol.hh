/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_PROTOCOL_HH__
#define   __POKEMONISM_SDK_INTERFACE_PROTOCOL_HH__

namespace pokemonism::sdk::interface {

    class protocol {
    public:     protocol(void) {}
    public:     virtual ~protocol(void) {}
    public:     protocol(const interface::protocol & o) = delete;
    public:     protocol(interface::protocol && o) noexcept = delete;
    public:     interface::protocol & operator=(const interface::protocol & o) = delete;
    public:     interface::protocol & operator=(interface::protocol && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_PROTOCOL_HH__