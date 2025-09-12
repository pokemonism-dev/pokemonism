/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_WINDOW_APPLICATION_HH__

#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/sdk/application.hh>

namespace pokemonism::window {

    class Window;

    class Application : public pokemonism::sdk::Application {
    protected:  using Collection = pokemonism::sdk::LinkedList<Application, Window>;
    private:    unsigned long   size;
    private:    Window *        head;
    private:    Window *        tail;
    public:     virtual Window * add(Window * node);
    public:     virtual Window * del(Window * node);
    public:     virtual void clear(void);
    public:     int run(void) override;
    public:     Application(void);
    public:     ~Application(void) override;
    public:     Application(const Application & o) = delete;
    public:     Application(Application && o) noexcept = delete;
    public:     Application & operator=(const Application & o) = delete;
    public:     Application & operator=(Application && o) noexcept = delete;
    public:     friend Collection;
    };

}

#endif // __POKEMONISM_WINDOW_APPLICATION_HH__