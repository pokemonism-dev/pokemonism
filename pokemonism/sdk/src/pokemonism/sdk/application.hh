/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_SDK_APPLICATION_HH__
#define   __POKEMONISM_SDK_APPLICATION_HH__

#include <pokemonism/observable.hh>
#include <pokemonism/runnable.hh>
#include <pokemonism/synchronizable.hh>
#include <pokemonism/applicationable.hh>

namespace pokemonism {

    namespace sdk {

        template <class Super = pokemonism::Applicationable>
        class Application : public Super {
        public:     Application(void);
        public:     ~Application(void) override;
        public:     Application(const Application & o) = delete;
        public:     Application(Application && o) noexcept = delete;
        public:     Application & operator=(const Application & o) = delete;
        public:     Application & operator=(Application && o) noexcept = delete;
        };

        template<class Super>
        Application<Super>::Application(void) {

        }

        template<class Super>
        Application<Super>::~Application(void) {

        }


    }

    template <class Super = pokemonism::Applicationable> using Application = pokemonism::sdk::Application<Super>;

    /**
     * Application<WindowApplicationObserver<WindowApplication<>>>::applicationGen();
     */

}

#endif // __POKEMONISM_SDK_APPLICATION_HH__