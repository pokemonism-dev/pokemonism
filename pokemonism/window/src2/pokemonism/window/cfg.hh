/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_CFG_HH__
#define   __POKEMONISM_WINDOW_CFG_HH__

#include <pokemonism.hh>

namespace pokemonism::window {

    class WindowCfg {
    public:     static const WindowCfg defaultConfig;
    public:     WindowCfg(void);
    public:     virtual ~WindowCfg(void);
    public:     WindowCfg(const WindowCfg & o);
    public:     WindowCfg(WindowCfg && o) noexcept;
    public:     WindowCfg & operator=(const WindowCfg & o);
    public:     WindowCfg & operator=(WindowCfg && o) noexcept;
    };

}

#endif // __POKEMONISM_WINDOW_CFG_HH__