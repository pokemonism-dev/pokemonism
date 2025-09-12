/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_VULKAN_HH__
#define   __POKEMONISM_VULKAN_HH__

#include <pokemonism/sdk/application.hh>

namespace pokemonism::vulkan {

    class Vulkan {
    public:     static void init(void);
    public:     static void term(void);
    public:     inline Vulkan(void);
    public:     inline virtual ~Vulkan(void);
    public:     Vulkan(const Vulkan & o) = delete;
    public:     Vulkan(Vulkan && o) noexcept = delete;
    public:     Vulkan & operator=(const Vulkan & o) = delete;
    public:     Vulkan & operator=(Vulkan && o) noexcept = delete;
    };

    inline Vulkan::Vulkan(void) {

    }

    inline Vulkan::~Vulkan(void) {

    }

}

#endif // __POKEMONISM_VULKAN_HH__