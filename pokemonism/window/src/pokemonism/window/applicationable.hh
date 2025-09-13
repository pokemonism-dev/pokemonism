/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_APPLICATIONABLE_HH__
#define   __POKEMONISM_WINDOW_APPLICATIONABLE_HH__

#include <pokemonism/applicationable.hh>

namespace pokemonism {

    namespace window {
        class WindowApplicationable : public Applicationable {
        public:     inline WindowApplicationable(void);
        public:     inline ~WindowApplicationable(void) override;
        public:     WindowApplicationable(const WindowApplicationable & o) = delete;
        public:     WindowApplicationable(WindowApplicationable && o) noexcept = delete;
        public:     WindowApplicationable & operator=(const WindowApplicationable & o) = delete;
        public:     WindowApplicationable & operator=(WindowApplicationable && o) noexcept = delete;
        };

        inline WindowApplicationable::WindowApplicationable(void) {

        }

        inline WindowApplicationable::~WindowApplicationable(void) {

        }
    }

    using WindowApplicationable  = pokemonism::window::WindowApplicationable;
}

#endif // __POKEMONISM_WINDOW_APPLICATIONABLE_HH__