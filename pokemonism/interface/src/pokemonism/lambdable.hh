/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#ifndef   __POKEMONISM_LAMBDABLE_HH__
#define   __POKEMONISM_LAMBDABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {

    struct lambdable {
    public:     template <typename returnable> struct call { typedef returnable (*type)(void); };
    public:     template <typename... argumentSet> struct run { typedef void (*type)(argumentSet...); };
    public:     template <typename returnable, typename... argumentSet> struct fun { typedef returnable (*type)(argumentSet...); };
    };

}

#endif // __POKEMONISM_LAMBDABLE_HH__