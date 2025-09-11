/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SDK_FUNCTIONABLE_HH__
#define   __POKEMONISM_SDK_FUNCTIONABLE_HH__

#include <pokemonism/sdk/primitivable.hh>

namespace pokemonism::sdk {

    template <typename outputable = primitivable, typename... argumentable>
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

#endif // __POKEMONISM_SDK_FUNCTIONABLE_HH__