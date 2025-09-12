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

namespace pokemonism::sdk {

    /**
     * @class       pokemonism::sdk::Application
     * @brief       어플리케이션 라이브러리로 사용자는 상속하여 사용할 수 있다.
     * @details     콘솔과 윈도우즈로 나뉜다.
     *              콘솔과 윈도우즈 어플리케이션을 어떻게 처리해야할까?
     *
     *
     */
    class Application : public Observable<Application, Observerable<Application, tag::NondisposableTag>, Runnable<Synchronizable<>>> {
    protected:  Synchronizable * synchronizer;
    protected:  Observable<Application, tag::NondisposableTag> * observable;
    protected:  inline int lock(void) override;
    protected:  inline int unlock(void) override;
    protected:  inline int wait(void) override;
    protected:  inline int wakeup(void) override;
    protected:  inline int wait(long second, long nano) override;
    protected:  inline int wakeup(bool all) override;
    public:     inline Observerable<Application, tag::NondisposableTag> * subscribe(Observerable<Application, tag::NondisposableTag> * o) override;
    public:     Application(void);
    public:     ~Application(void) override;
    public:     Application(const Application & o) = delete;
    public:     Application(Application && o) noexcept = delete;
    public:     Application & operator=(const Application & o) = delete;
    public:     Application & operator=(Application && o) noexcept = delete;
    };

    inline int Application::lock(void) {
        return synchronizer != nullptr ? synchronizer->lock() : declaration::fail;
    }

    inline int Application::unlock(void) {
        return synchronizer != nullptr ? synchronizer->unlock() : declaration::fail;
    }

    inline int Application::wait(void) {
        return synchronizer != nullptr ? synchronizer->wait() : declaration::fail;
    }

    inline int Application::wakeup(void) {
        return synchronizer != nullptr ? synchronizer->wakeup() : declaration::fail;
    }

    inline int Application::wait(long second, long nano) {
        return synchronizer != nullptr ? synchronizer->wait(second, nano) : declaration::fail;
    }

    inline int Application::wakeup(bool all) {
        return synchronizer != nullptr ? synchronizer->wakeup(all) : declaration::fail;
    }

    /**
     * 등록되지 않는다면, 리턴하여 사용자가 삭제할 수 있도록 한다.
     * 만약에 리턴이 존재한다면 등록에 실패한 것이다.
     */
    inline Observerable<Application, tag::NondisposableTag> * Application::subscribe(Observerable<Application, tag::NondisposableTag> * o) {
        if (observable != nullptr) return subscribe(o);

        return o;
    }

}

#endif // __POKEMONISM_SDK_APPLICATION_HH__