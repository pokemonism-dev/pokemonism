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

#include <pokemonism/sdk/exception.hh>
#include <pokemonism/applicationable.hh>

namespace pokemonism {

    namespace sdk {
        /**
         * 이 구조의 어플리케이션 클래스는 다양한 어플리케이션을 만들기 좋다.
         *
         */
        template <class Super = Applicationable>
        class Application : public Super {
        protected:  static Application<Super> * singleton;
        public:     static Application<Super> * gen(void);
        public:     static Application<Super> * get(void);
        public:     static int exec(Application<Super> * application);
        protected:  Application(void);
        protected:  ~Application(void) override;
        public:     Application(const Application & o) = delete;
        public:     Application(Application && o) noexcept = delete;
        public:     Application & operator=(const Application & o) = delete;
        public:     Application & operator=(Application && o) noexcept = delete;
        };

        template<class Super>
        Application<Super> * Application<Super>::singleton = nullptr;

        template<class Super>
        Application<Super> * Application<Super>::gen(void) {
            if (Applicationable::singleton == nullptr) {
                Applicationable::singleton = Application<Super>::singleton = new Application<Super>();

                return Application<Super>::singleton;
            }
            return nullptr;
        }

        template<class Super>
        Application<Super> * Application<Super>::get(void) {
            return Application<Super>::singleton;
        }

        template<class Super>
        int Application<Super>::exec(Application<Super> * application) {
            pokemon_develop_check(application == nullptr || application != Applicationable::singleton, return declaration::fail);

            const int ret = application->run();

            delete Applicationable::singleton;
            Applicationable::singleton = nullptr;
            Application<Super>::singleton = nullptr;

            return ret;
        }

        template<class Super>
        inline Application<Super>::Application(void) {

        }

        template<class Super>
        inline Application<Super>::~Application(void) {

        }

    }

    template <class Super = pokemonism::Applicationable> using Application = pokemonism::sdk::Application<Super>;

}

#endif // __POKEMONISM_SDK_APPLICATION_HH__