/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_WINDOW_APPLICATION_HH__

#include <pokemonism.hh>

#include <pokemonism/window/interface/application.hh>
#include <pokemonism/window/platform/application.hh>

namespace pokemonism::window {

    template <class Super = interface::WindowApplication>
    class WindowApplication : public Super {

    };

    class Application : public pokemonism::window::interface::Application {
    protected:  static pokemonism::window::Application & applicationGen(void);
    protected:  pokemonism::window::interface::Application & adapter;
    public:     const char * platformNameGet(void) const noexcept override;
    protected:  inline Application(void);
    public:     inline ~Application(void) override;
    public:     Application(const Application & o) = delete;
    public:     Application(Application && o) noexcept = delete;
    public:     Application & operator=(const Application & o) = delete;
    public:     Application & operator=(Application && o) noexcept = delete;
    };

    inline const char * Application::platformNameGet(void) const noexcept {
        return adapter.platformNameGet();
    };

    inline Application::Application(void) : adapter(pokemonism::window::platform::applicationGet()) {

    }

    inline Application::~Application(void) {

    }

}

#endif // __POKEMONISM_WINDOW_APPLICATION_HH__
