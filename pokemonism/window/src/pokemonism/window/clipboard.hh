/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_CLIPBOARD_HH__
#define   __POKEMONISM_WINDOW_CLIPBOARD_HH__

#include <pokemonism/sdk/string.hh>

namespace pokemonism::window {

    class Clipboard {
    public:     virtual String get(void);
    public:     virtual void set(const String & o);
    public:     virtual void set(String && o);
    public:     Clipboard(void) {}
    public:     virtual ~Clipboard(void) {}
    public:     Clipboard(const Clipboard & o) = delete;
    public:     Clipboard(Clipboard && o) noexcept = delete;
    public:     Clipboard & operator=(const Clipboard & o) = delete;
    public:     Clipboard & operator=(Clipboard && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_CLIPBOARD_HH__