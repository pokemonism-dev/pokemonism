/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_THROWABLE_HH__
#define   __POKEMONISM_THROWABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {

        class throwable : public declaration::type::exception {
        public:     throwable(void) {}
        public:     ~throwable(void) override {}
        public:     throwable(const throwable & o) = delete;
        public:     throwable(throwable && o) noexcept = delete;
        public:     throwable & operator=(const throwable & o) = delete;
        public:     throwable & operator=(throwable && o) noexcept = delete;
        };

    }

    using throwable = pokemon::throwable;
}

#endif // __POKEMONISM_THROWABLE_HH__