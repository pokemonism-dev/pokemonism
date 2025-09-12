/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_CONFIG_HH__
#define   __POKEMONISM_WINDOW_CONFIG_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism::window {

    template <class Super = Virtualable>
    class WindowConfig : public Super {
    protected:  bool button;
    protected:  unsigned int angle;
    protected:  unsigned int platform;
    protected:  WindowConfig(void);
    public:     ~WindowConfig(void) override;
    public:     WindowConfig(const WindowConfig & o) = delete;
    public:     WindowConfig(WindowConfig && o) noexcept = delete;
    public:     WindowConfig & operator=(const WindowConfig & o) = delete;
    public:     WindowConfig & operator=(WindowConfig && o) noexcept = delete;
    };

    template <class Super>
    WindowConfig<Super>::WindowConfig(void) : button(true), angle(), platform(declaration::none) {

    }

    template <class Super>
    WindowConfig<Super>::~WindowConfig(void) {

    }


}

#endif // __POKEMONISM_WINDOW_CONFIG_HH__