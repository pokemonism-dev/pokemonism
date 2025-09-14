/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_LIB_HH__
#define   __POKEMONISM_WINDOW_COCOA_LIB_HH__

#include <pokemonism/window/src/pokemonism/window.old/lib.hh>

namespace pokemonism::window {

    class WindowCocoaLib : public WindowLib {
    public:     int lock(void) override;
    public:     int unlock(void) override;
    public:     int wait(void) override;
    public:     int wakeup(void) override;
    public:     int wait(long second, long nano) override;
    public:     int wakeup(bool all) override;
    protected:  WindowCocoaLib(void);
    protected:  ~WindowCocoaLib(void) override;
    public:     WindowCocoaLib(const WindowCocoaLib & o) = delete;
    public:     WindowCocoaLib(WindowCocoaLib && o) noexcept = delete;
    public:     WindowCocoaLib & operator=(const WindowCocoaLib & o) = delete;
    public:     WindowCocoaLib & operator=(WindowCocoaLib && o) noexcept = delete;
    public:     friend class WindowLib;
    };

}

#endif // __POKEMONISM_WINDOW_COCOA_LIB_HH__