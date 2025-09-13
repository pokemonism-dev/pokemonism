/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */


#include "cfg.hh"

namespace pokemonism::window {

    const WindowCfg WindowCfg::defaultConfig;

    WindowCfg::WindowCfg(void) {

    }

    WindowCfg::~WindowCfg(void) {

    }

    WindowCfg::WindowCfg(const WindowCfg & o) {

    }

    WindowCfg::WindowCfg(WindowCfg && o) noexcept {

    }

    WindowCfg & WindowCfg::operator=(const WindowCfg & o) {
        return *this;
    }

    WindowCfg & WindowCfg::operator=(WindowCfg && o) noexcept {
        return *this;
    }

}