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

#include <pokemonism.hh>

namespace pokemonism::window {

    class Image;
    class Cursor;

    class Window {
    public:     Keyboard keyboard;
    public:     static void init(void);
    public:     static void term(void);
    public:     virtual void cursorPositionGet(double * x, double * y);
    public:     virtual void cursorPositionSet(double x, double y);
    public:     virtual Cursor * cursorGen(Image * image, int x, int y);
    public:     virtual Cursor * cursorGen(int shape);
    public:     virtual void cursorRel(Cursor * cursor);
    public:     virtual void cursorSet(Cursor * cursor);
    public:     virtual void keyboardCallbackSet()

    public:     Window(void);
    public:     virtual ~Window(void);
    public:     Window(const Window & o) = delete;
    public:     Window(Window && o) noexcept = delete;
    public:     Window & operator=(const Window & o) = delete;
    public:     Window & operator=(Window && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_HH__