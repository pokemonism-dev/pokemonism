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
        template <class super = applicationable>
        class application : public super {
        protected:  static application<super> * singleton;
        public:     static application<super> * gen(void);
        public:     static application<super> * get(void);
        public:     static int exec(application<super> * o);
        public:     application(void);
        public:     ~application(void) override;
        public:     application(const application & o) = delete;
        public:     application(application && o) noexcept = delete;
        public:     application & operator=(const application & o) = delete;
        public:     application & operator=(application && o) noexcept = delete;
        };

        template<class super>
        application<super> * application<super>::singleton = nullptr;

        template<class super>
        application<super> * application<super>::gen(void) {
            if (applicationable::singleton == nullptr) {
                applicationable::singleton = application<super>::singleton = new application<super>();

                return application<super>::singleton;
            }
            return nullptr;
        }

        template<class super>
        application<super> * application<super>::get(void) {
            return application<super>::singleton;
        }

        template<class super>
        int application<super>::exec(application<super> * o) {
            pokemon_develop_check(o == nullptr || o != applicationable::singleton, return declaration::fail);

            const int ret = o->run();

            delete applicationable::singleton;
            applicationable::singleton = nullptr;
            application<super>::singleton = nullptr;

            return ret;
        }

        template<class super>
        inline application<super>::application(void) {

        }

        template<class super>
        inline application<super>::~application(void) {

        }

    }

    template <class super = pokemonism::applicationable> using application = pokemonism::sdk::application<super>;

}

#endif // __POKEMONISM_SDK_APPLICATION_HH__