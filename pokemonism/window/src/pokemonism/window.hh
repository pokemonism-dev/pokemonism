/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_HH__
#define   __POKEMONISM_WINDOW_HH__

#include <pokemonism/window/interface/window.hh>

#include <pokemonism/window/input/mouse.hh>
#include <pokemonism/window/input/keyboard.hh>
#include <pokemonism/window/monitor.hh>

namespace pokemonism::window {

    class Image;
    class Cursor;

    class Application;

    class Window : public window::interface::Window {
    protected:  Application *                   container;
    protected:  Window *                        prev;
    protected:  Window *                        next;
    protected:  window::interface::Window *     window;
    public:     window::interface::Keyboard &   keyboard;
    public:     window::interface::Mouse &      mouse;
    public:     window::interface::Monitor &    monitor;
    protected:  interface::Keyboard & keyboardGet(void) const override { return keyboard; };
    protected:  interface::Mouse & mouseGet(void) const override { return mouse; }
    protected:  interface::Monitor & monitorGet(void) const override { return monitor; }
    public:     void titleSet(const char * name) override { window->titleSet(name); }
    // public:     virtual int gen(void) = 0;
    // public:     virtual int rel(void) = 0;
    // public:     virtual void titleSet(const char * name) = 0;
    // public:     virtual void iconSet(void) = 0;
    // public:     virtual void positionGet(int * x, int * y) = 0;
    // public:     virtual void positionSet(int x, int y) = 0;
    // public:     virtual void sizeGet(int * width, int * height) = 0;
    // public:     virtual void sizeSet(int width, int height) = 0;
    // public:     virtual void minimumSizeSet(int width, int height) = 0;
    // public:     virtual void maximumSizeSet(int width, int height) = 0;
    // public:     virtual void aspectRatioSet(int number, int denominator) = 0;
    // public:     virtual void frameBufferSizeGet(int * width, int * height) = 0;
    // public:     virtual void frameSizeGet(int * left, int * top, int * right, int * bottom) = 0;
    // public:     virtual void scaleGet(int * x, int * y) = 0;
    // public:     virtual void iconify(void) = 0;
    // public:     virtual void restore(void) = 0;
    // public:     virtual void maximize(void) = 0;
    // public:     virtual void show(void) = 0;
    // public:     virtual void hide(void) = 0;
    // public:     virtual void attention(void) = 0;
    // public:     virtual void focus(void) = 0;
    // public:     virtual void visible(void) = 0;
    // public:     virtual void iconified(void) = 0;
    // public:     virtual void maximized(void) = 0;
    // public:     virtual void hovered(void) = 0;
    // public:     virtual bool transparentGet(void) = 0;
    // public:     virtual float opacityGet(void) = 0;
    // public:     virtual void opacitySet(float v) = 0;
    // public:     virtual bool resizableSet(void) = 0;
    // public:     virtual bool decoratedSet(void) = 0;
    // public:     virtual void floatingSet(void) = 0;
    // public:     virtual void poll(void) = 0;
    // public:     virtual void wait(void) = 0;
    // public:     virtual void wait(long second, long nano) = 0;
    // public:     virtual void post(void) = 0;
    public:     explicit Window(interface::Window * window);
    public:     Window(void) = delete;
    public:     ~Window(void) override;
    public:     Window(const Window & o) = delete;
    public:     Window(Window && o) noexcept = delete;
    public:     Window & operator=(const Window & o) = delete;
    public:     Window & operator=(Window && o) noexcept = delete;
    public:     friend pokemonism::sdk::LinkedList<Application, Window>;
    };

}

#endif // __POKEMONISM_WINDOW_HH__