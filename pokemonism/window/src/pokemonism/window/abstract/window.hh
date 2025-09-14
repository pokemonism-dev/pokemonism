/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_ABSTRACT_WINDOW_HH__
#define   __POKEMONISM_WINDOW_ABSTRACT_WINDOW_HH__

#include <pokemonism/window/window.hh>

#include <pokemonism/sdk/linked/list.hh>

namespace pokemonism::window {

    class AbstractWindowApplication;
    class PlatformWindow;

    class AbstractWindow : public Window {
    protected:  AbstractWindowApplication * container;
    protected:  AbstractWindow * prev;
    protected:  AbstractWindow * next;
    protected:  PlatformWindow * adapter;
    protected:  explicit AbstractWindow(PlatformWindow * window);
    protected:  inline AbstractWindow(void);
    public:     ~AbstractWindow(void) override;
    public:     AbstractWindow(const AbstractWindow & o) = delete;
    public:     AbstractWindow(AbstractWindow && o) noexcept = delete;
    public:     AbstractWindow & operator=(const AbstractWindow & o) = delete;
    public:     AbstractWindow & operator=(AbstractWindow && o) noexcept = delete;
    public:     friend AbstractWindowApplication;
    public:     friend pokemonism::sdk::LinkedList<AbstractWindowApplication, AbstractWindow>;
    };

    inline AbstractWindow::AbstractWindow(void) : container(nullptr), prev(nullptr), next(nullptr), adapter(nullptr) {

    }



}

#endif // __POKEMONISM_WINDOW_ABSTRACT_WINDOW_HH__