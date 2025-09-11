/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_FILE_HH__
#define   __POKEMONISM_SDK_INTERFACE_FILE_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    class file {
    public:     file(void) {}
    public:     virtual ~file(void) {}
    public:     file(const interface::file & o) = delete;
    public:     file(interface::file && o) noexcept = delete;
    public:     interface::file & operator=(const interface::file & o) = delete;
    public:     interface::file & operator=(interface::file && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_FILE_HH__