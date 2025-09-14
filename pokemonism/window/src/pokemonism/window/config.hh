/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_WINDOW_CONFIG_HH__
#define   __POKEMONISM_WINDOW_CONFIG_HH__

#include <pokemonism/window.hh>
#include <pokemonism/sdk/string.hh>

namespace pokemonism {

    struct window::config {
    public:     string              title;
    public:     window::rectangle   rect;
    };

}

#endif // __POKEMONISM_WINDOW_CONFIG_HH__