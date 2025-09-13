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

#include <pokemonism/applicationable.hh>

namespace pokemonism {

    namespace sdk {
        /**
         * 이 구조의 어플리케이션 클래스는 다양한 어플리케이션을 만들기 좋다.
         *
         *
         * @todo        Support Singleton
         *
         * @tparam Super
         */
        template <class Super = pokemonism::Applicationable>
        class Application : public Super {
        protected:  Application(void);
        protected:  ~Application(void) override;
        public:     Application(const Application & o) = delete;
        public:     Application(Application && o) noexcept = delete;
        public:     Application & operator=(const Application & o) = delete;
        public:     Application & operator=(Application && o) noexcept = delete;
        };

        template<class Super>
        inline Application<Super>::Application(void) {

        }

        template<class Super>
        inline Application<Super>::~Application(void) {

        }


    }

    template <class Super = pokemonism::Applicationable> using Application = pokemonism::sdk::Application<Super>;

    /**
     * Application<WindowApplicationObserver<WindowApplication<>>>::applicationGen();
     */

}

#endif // __POKEMONISM_SDK_APPLICATION_HH__