/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_WINDOW_HH__
#define   __POKEMONISM_WINDOW_HH__

#include <pokemonism/applicationable.hh>

namespace pokemonism {



    // namespace abstract {
    //     class window;
    // }
    //
    // class window {
    // public:     struct config;
    // public:     class applicationable : public pokemonism::applicationable {
    //             public:     virtual window * windowGen(const window::config & o) = 0;
    //             public:     applicationable(void);
    //             public:     ~applicationable(void) override;
    //             public:     applicationable(const window::applicationable & o);
    //             public:     applicationable(window::applicationable && o) noexcept;
    //             public:     window::applicationable & operator=(const window::applicationable & o);
    //             public:     window::applicationable & operator=(window::applicationable && o) noexcept;
    //             };
    // public:     template <class super = abstract::window::application>
    //                 class application : public super {
    //
    //
    //             };
    // public:     inline window(void);
    // public:     inline virtual ~window(void);
    // public:     inline window(const window & o);
    // public:     inline window(window && o) noexcept;
    // public:     inline window & operator=(const window & o);
    // public:     inline window & operator=(window && o) noexcept;
    // };
    //
    // inline window::window(void) {
    //
    // }
    //
    // inline window::~window(void) {
    //
    // }
    //
    // inline window::window(const window & o) {
    //
    // }
    //
    // inline window::window(window && o) noexcept {
    //
    // }
    //
    // inline window & window::operator=(const window & o) {
    //     return *this;
    // }
    //
    // inline window & window::operator=(window && o) noexcept {
    //     return *this;
    // }

}

#endif // __POKEMONISM_WINDOW_HH__