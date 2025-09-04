/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_CALLABLE_HH__
#define   __POKEMONISM_CALLABLE_HH__

#include <pokemonism/primitivable.hh>

namespace pokemonism {

    template <typename outputable = primitivable>
    class callable {
    public:     virtual outputable * operator()(void) = 0;
    public:     callable(void) {}
    public:     virtual ~callable(void) {}
    public:     callable(const callable<outputable> & o) = delete;
    public:     callable(callable<outputable> && o) noexcept = delete;
    public:     callable<outputable> & operator=(const callable<outputable> & o) = delete;
    public:     callable<outputable> & operator=(callable<outputable> && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_CALLABLE_HH__