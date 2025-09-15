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

#include <pokemonism/window.hh>

namespace pokemonism::vulkan {

    class window : public pokemonism::window {
    public:     class application {

                };
    public:     window(void);
    public:     ~window(void) override;
    public:     window(const vulkan::window & o) = delete;
    public:     window(vulkan::window && o) noexcept = delete;
    public:     vulkan::window & operator=(const vulkan::window & o) = delete;
    public:     vulkan::window & operator=(vulkan::window && o) noexcept = delete;
    };

    // class Vulkan {
    // public:     static void init(void);
    // public:     static void term(void);
    // public:     inline Vulkan(void);
    // public:     inline virtual ~Vulkan(void);
    // public:     Vulkan(const Vulkan & o) = delete;
    // public:     Vulkan(Vulkan && o) noexcept = delete;
    // public:     Vulkan & operator=(const Vulkan & o) = delete;
    // public:     Vulkan & operator=(Vulkan && o) noexcept = delete;
    // };
    //
    // inline Vulkan::Vulkan(void) {
    //
    // }
    //
    // inline Vulkan::~Vulkan(void) {
    //
    // }

}

#endif // __POKEMONISM_VULKAN_HH__