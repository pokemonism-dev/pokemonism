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

#include <../../../sdk/src/pokemonism/application.hh>

namespace pokemonism::vulkan {

    class Vulkan : public pokemonism::sdk::Application {
    public:     static void init(void);
    public:     static void term(void);
    public:     int run(void) override;
    public:     inline Vulkan(void);
    public:     inline ~Vulkan(void) override;
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