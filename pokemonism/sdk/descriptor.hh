/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_DESCRIPTOR_HH__
#define   __POKEMONISM_SDK_DESCRIPTOR_HH__

#include <pokemonism/sdk/sync.hh>

namespace pokemonism::sdk {

    class descriptor : public synchronizable {
    public:     typedef int         type;
    public:     descriptor(void) {}
    public:     ~descriptor(void) override {}
    public:     descriptor(const descriptor & o) = delete;
    public:     descriptor(descriptor && o) noexcept = delete;
    public:     descriptor & operator=(const descriptor & o) = delete;
    public:     descriptor & operator=(descriptor && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_DESCRIPTOR_HH__