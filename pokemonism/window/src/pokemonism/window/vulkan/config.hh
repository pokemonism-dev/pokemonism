/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_VULKAN_CONFIG_HH__
#define   __POKEMONISM_WINDOW_VULKAN_CONFIG_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism::window {

    template <class Super = Virtualable>
    class WindowVulkanConfig : public Super {
    public:     WindowVulkanConfig(void);
    public:     ~WindowVulkanConfig(void) override;
    public:     WindowVulkanConfig(const WindowVulkanConfig & o) = delete;
    public:     WindowVulkanConfig(WindowVulkanConfig && o) noexcept = delete;
    public:     WindowVulkanConfig & operator=(const WindowVulkanConfig & o) = delete;
    public:     WindowVulkanConfig & operator=(WindowVulkanConfig && o) noexcept = delete;
    };

    template<class Super>
    WindowVulkanConfig<Super>::WindowVulkanConfig(void) {

    }

    template<class Super>
    WindowVulkanConfig<Super>::~WindowVulkanConfig(void) {

    }

}

#endif // __POKEMONISM_WINDOW_VULKAN_CONFIG_HH__

