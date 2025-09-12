/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_CONFIG_HH__
#define   __POKEMONISM_WINDOW_COCOA_CONFIG_HH__

#include <pokemonism/window/config.hh>
#include <pokemonism/window/vulkan/config.hh>

namespace pokemonism::window {

    class WindowCocoaConfig : public WindowVulkanConfig<WindowConfig<>> {
    protected:  bool menu;
    public:     WindowCocoaConfig(void);
    public:     ~WindowCocoaConfig(void) override;
    public:     WindowCocoaConfig(const WindowCocoaConfig & o) = delete;
    public:     WindowCocoaConfig(WindowCocoaConfig && o) noexcept = delete;
    public:     WindowCocoaConfig & operator=(const WindowCocoaConfig & o) = delete;
    public:     WindowCocoaConfig & operator=(WindowCocoaConfig && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_COCOA_CONFIG_HH__