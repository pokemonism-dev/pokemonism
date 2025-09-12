/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_CURSOR_HH__
#define   __POKEMONISM_WINDOW_COCOA_CURSOR_HH__

#include <pokemonism/window/cursor.hh>

namespace pokemonism::window {

    class CocoaCursor : public Cursor {
    public:     CocoaCursor(void);
    public:     ~CocoaCursor(void) override;
    public:     CocoaCursor(const CocoaCursor & o) = delete;
    public:     CocoaCursor(CocoaCursor && o) noexcept = delete;
    public:     CocoaCursor & operator=(const CocoaCursor & o) = delete;
    public:     CocoaCursor & operator=(CocoaCursor && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_COCOA_CURSOR_HH__