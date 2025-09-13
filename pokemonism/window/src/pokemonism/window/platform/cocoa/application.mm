/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#include <Cocoa/Cocoa.h>

#include "../application.hh"

namespace pokemonism::window {

    class CocoaPlatformWindowApplication : public PlatformWindowApplication {
    public:    const char * platformNameGet(void) const noexcept override;
    public:    int run(void) override;
    };

    const char * CocoaPlatformWindowApplication::platformNameGet(void) const noexcept {
        return "cocoa";
    }

    int CocoaPlatformWindowApplication::run(void) {
        return declaration::success;
    }

    PlatformWindowApplication & PlatformWindowApplication::get(void) {
        static CocoaPlatformWindowApplication singleton;
        return singleton;
    }



//    namespace cocoa {
//        class Application : public pokemonism::window::interface::Application {
//        public:    static Application singleton;
//        public:    inline const char * platformNameGet(void) const noexcept override;
//        public:    inline pokemonism::window::interface::Window * gen(const pokemonism::window::interface::WindowConfig & config) override;
//        public:    inline int run(void) override;
//        public:    inline Application(void);
//        public:    inline ~Application(void) override;
//        public:    Application(const Application & o) = delete;
//        public:    Application(Application && o) noexcept = delete;
//        public:    Application & operator=(const Application & o) = delete;
//        public:    Application & operator=(Application && o) noexcept = delete;
//        };
//
//        Application Application::singleton;
//
//        inline const char * Application::platformNameGet(void) const noexcept {
//            return "cocoa";
//        }
//
//        inline pokemonism::window::interface::Window * Application::gen(const pokemonism::window::interface::WindowConfig & config) {
//            return nullptr;
//        }
//
//        inline int Application::run(void) {
//            return declaration::success;
//        }
//
//        inline Application::Application(void) {
//        }
//
//        inline Application::~Application(void) {
//        }
//    }
//
//    pokemonism::window::interface::Application & applicationGet(void) {
//        return pokemonism::window::platform::cocoa::Application::singleton;
//    }

}
