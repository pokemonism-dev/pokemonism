/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_LIB_HH__
#define   __POKEMONISM_WINDOW_LIB_HH__

#include <pokemonism/synchronizable.hh>

namespace pokemonism::window {

    class WindowLib : public Synchronizable<> {
    protected:  static WindowLib * singleton;
    public:     static void init(void);
    public:     static void term(void);
    public:     WindowLib(void);
    public:     ~WindowLib(void) override;
    public:     WindowLib(const WindowLib & o) = delete;
    public:     WindowLib(WindowLib && o) noexcept = delete;
    public:     WindowLib & operator=(const WindowLib & o) = delete;
    public:     WindowLib & operator=(WindowLib && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_LIB_HH__
