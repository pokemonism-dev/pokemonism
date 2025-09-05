/**
 * @file            pokemonism/interface/functionable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_FUNCTIONABLE_HH__
#define   __POKEMONISM_INTERFACE_FUNCTIONABLE_HH__

#include <pokemonism/interface/primitivable.hh>

namespace pokemonism {
    namespace interface {

        template <class outputable = primitivable, typename... argumentable>
        class functionable {
        public:     virtual outputable * operator()(argumentable... args) = 0;
        public:     functionable(void) {}
        public:     virtual ~functionable(void) {}
        public:     functionable(const functionable<outputable, argumentable...> & o) = delete;
        public:     functionable(functionable<outputable, argumentable...> && o) noexcept = delete;
        public:     functionable<outputable, argumentable...> & operator=(const functionable<outputable, argumentable...> & o) = delete;
        public:     functionable<outputable, argumentable...> & operator=(functionable<outputable, argumentable...> && o) noexcept = delete;
        };

    }

    template <class outputable = primitivable, typename... argumentable> using functionable = interface::functionable<outputable, argumentable...>;

}

#endif // __POKEMONISM_INTERFACE_FUNCTIONABLE_HH__