/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_DIRECTORY_HH__
#define   __POKEMONISM_SDK_INTERFACE_DIRECTORY_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    class directory : public interface::descriptor {
    public:     directory(void) {}
    public:     ~directory(void) override {}
    public:     directory(const interface::directory & o) = delete;
    public:     directory(interface::directory && o) noexcept = delete;
    public:     interface::directory & operator=(const interface::directory & o) = delete;
    public:     interface::directory & operator=(interface::directory && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_DIRECTORY_HH__