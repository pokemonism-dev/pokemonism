/**
 * @file            pokemonism/interface/callable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_CALLABLE_HH__
#define   __POKEMONISM_INTERFACE_CALLABLE_HH__

#include <pokemonism/interface/primitivable.hh>

namespace pokemonism {
    namespace interface {

        template <class outputable = primitivable>
        class callable {
        public:     virtual outputable * operator()(void) = 0;
        public:     callable(void) {}
        public:     virtual ~callable(void) {}
        public:     callable(const callable<outputable> & o) = delete;
        public:     callable(callable<outputable> && o) noexcept = delete;
        public:     callable<outputable> & operator=(const callable<outputable> & o) = delete;
        public:     callable<outputable> & operator=(callable<outputable> && o) noexcept = delete;
        };

    };

    template <class outputable = primitivable> using callable = interface::callable<outputable>;

}

#endif // __POKEMONISM_INTERFACE_CALLABLE_HH__