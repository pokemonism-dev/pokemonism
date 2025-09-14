/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#ifndef   __POKEMONISM_PLATFORM_WINDOW_HH__
#define   __POKEMONISM_PLATFORM_WINDOW_HH__

#include <pokemonism/interface/window.hh>

namespace pokemonism::platform {

    class window : public interface::window {
    public:     class application : public interface::window::application {
                public:     platform::window * windowGen(const interface::window::config & o);
                };
    };

}

#endif // __POKEMONISM_PLATFORM_WINDOW_HH__