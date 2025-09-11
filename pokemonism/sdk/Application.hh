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

#include <pokemonism.hh>

namespace pokemonism::sdk {

    template <class T>
    class Observable {
    public:     Observable(void) {}
    public:     virtual ~Observable(){}
    };

    /**
     * @class       pokemonism::sdk::Application
     * @brief       어플리케이션 라이브러리로 사용자는 상속하여 사용할 수 있다.
     * @details     콘솔과 윈도우즈로 나뉜다.
     *
     * Application.run()
     *
     * application::run();
     *
     */
    class Application : public Observable<Application> {
    public:     virtual int run(void);
    public:     Application(void) {}
    public:     ~Application(void) override {}
    public:     Application(const Application & o) = delete;
    public:     Application(Application && o) noexcept = delete;
    public:     Application & operator=(const Application & o) = delete;
    public:     Application & operator=(Application && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_APPLICATION_HH__