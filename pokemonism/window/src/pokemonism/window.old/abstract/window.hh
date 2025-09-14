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

#include <pokemonism/window/src/pokemonism/window.old/window.hh>
#include <pokemonism/window/src/pokemonism/window.old/platform/window.hh>

#include <pokemonism/sdk/linked/list.hh>

namespace pokemonism::window {


    // namespace abstract {
    //     class window : public windo
    // }


    //
    // class AbstractWindowApplication;
    // // class PlatformWindow;
    //
    // class AbstractWindow : public Window {
    // protected:  AbstractWindowApplication * container;
    // protected:  AbstractWindow * prev;
    // protected:  AbstractWindow * next;
    // protected:  PlatformWindow * adapter;
    // public:     int create(void) override { return adapter != nullptr ? adapter->create() : declaration::fail; }
    // public:     int destroy(void) override { return adapter != nullptr ? adapter->destroy() : declaration::fail; }
    // protected:  explicit AbstractWindow(PlatformWindow * window);
    // protected:  inline AbstractWindow(void);
    // public:     ~AbstractWindow(void) override;
    // public:     AbstractWindow(const AbstractWindow & o) = delete;
    // public:     AbstractWindow(AbstractWindow && o) noexcept = delete;
    // public:     AbstractWindow & operator=(const AbstractWindow & o) = delete;
    // public:     AbstractWindow & operator=(AbstractWindow && o) noexcept = delete;
    // public:     friend AbstractWindowApplication;
    // public:     friend pokemonism::sdk::LinkedList<AbstractWindowApplication, AbstractWindow>;
    // };
    //
    // inline AbstractWindow::AbstractWindow(void) : container(nullptr), prev(nullptr), next(nullptr), adapter(nullptr) {
    //
    // }



}

#endif // __POKEMONISM_WINDOW_ABSTRACT_WINDOW_HH__