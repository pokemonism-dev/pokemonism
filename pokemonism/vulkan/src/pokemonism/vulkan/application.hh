/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_VULKAN_APPLICATION_HH__
#define   __POKEMONISM_VULKAN_APPLICATION_HH__

#include <pokemonism/window/application.hh>

namespace pokemonism::vulkan {

    class Application : public window::Application {
    public:     Application(void);
    public:     ~Application(void) override;
    public:     Application(const Application & o) = delete;
    public:     Application(Application && o) noexcept = delete;
    public:     Application & operator=(const Application & o) = delete;
    public:     Application & operator=(Application && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_VULKAN_APPLICATION_HH__