/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#include <cstdio>

#include <pokemonism/window.hh>

#include "vulkan.hh"

namespace pokemonism::vulkan {

    void Vulkan::init(void) {

    }

    void Vulkan::term(void) {

    }

    int Vulkan::run(void) {
        try {
            Window::init();
            Vulkan::init();

            Vulkan::term();
            return declaration::success;
        } catch (const std::exception & e) {
            printf("%s\n", e.what());
        }
        return declaration::fail;
    }

}