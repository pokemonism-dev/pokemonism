/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_WINDOW_MONITOR_HH__
#define   __POKEMONISM_WINDOW_MONITOR_HH__

#include <pokemonism/collection/string.hh>
#include <pokemonism/window/src/pokemonism/window.old/structure/dimension.hh>

namespace pokemonism::window {

    class WindowMonitor {
    protected:  String name;
    protected:  Dimension dimension;
    public:     inline WindowMonitor(void);
    public:     inline virtual ~WindowMonitor(void);
    public:     inline WindowMonitor(const WindowMonitor & o);
    public:     inline WindowMonitor(WindowMonitor && o) noexcept;
    public:     inline WindowMonitor & operator=(const WindowMonitor & o);
    public:     inline WindowMonitor & operator=(WindowMonitor && o) noexcept;
    };

    inline WindowMonitor::WindowMonitor(void) {

    }

    inline WindowMonitor::~WindowMonitor(void) {

    }

    inline WindowMonitor::WindowMonitor(const WindowMonitor & o) {

    }

    inline WindowMonitor::WindowMonitor(WindowMonitor && o) noexcept {

    }

    inline WindowMonitor & WindowMonitor::operator=(const WindowMonitor & o) {
        return *this;
    }

    inline WindowMonitor & WindowMonitor::operator=(WindowMonitor && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_WINDOW_MONITOR_HH__