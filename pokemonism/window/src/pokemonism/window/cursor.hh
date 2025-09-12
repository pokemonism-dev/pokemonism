/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_CURSOR_HH__
#define   __POKEMONISM_WINDOW_CURSOR_HH__

#include <pokemonism.hh>

namespace pokemonism::window {

    class Cursor {
    public:     virtual void positionGet(double * x, double * y) = 0;
    public:     virtual void positionSet(double x, double y) = 0;
    public:     virtual void modeSet(int mode) = 0;
    public:     Cursor(void);
    public:     virtual ~Cursor(void);
    public:     Cursor(const Cursor & o) = delete;
    public:     Cursor(Cursor && o) noexcept = delete;
    public:     Cursor & operator=(const Cursor & o) = delete;
    public:     Cursor & operator=(Cursor && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_CURSOR_HH__