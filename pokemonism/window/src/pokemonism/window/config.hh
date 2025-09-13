/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_CONFIG_HH__
#define   __POKEMONISM_WINDOW_CONFIG_HH__

#include <pokemonism.hh>

namespace pokemonism::window {

    class WindowConfig {
    public:     inline WindowConfig(void);
    public:     inline virtual ~WindowConfig(void);
    public:     WindowConfig(const WindowConfig & o) = delete;
    public:     WindowConfig(WindowConfig && o) noexcept = delete;
    public:     WindowConfig & operator=(const WindowConfig & o) = delete;
    public:     WindowConfig & operator=(WindowConfig && o) noexcept = delete;
    };

    inline WindowConfig::WindowConfig(void) {

    }

    inline WindowConfig::~WindowConfig(void) {

    }

}

#endif // __POKEMONISM_WINDOW_CONFIG_HH__