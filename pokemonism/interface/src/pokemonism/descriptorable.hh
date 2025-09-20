/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 20, 2025
 */

#ifndef   __POKEMONISM_DESCRIPTORABLE_HH__
#define   __POKEMONISM_DESCRIPTORABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class super = virtualable>
    class descriptorable : super {
    protected:  constexpr static int invalid = -1;
    public:     descriptorable(void) {}
    public:     ~descriptorable(void) override {}
    public:     descriptorable(const descriptorable<super> & o) {}
    public:     descriptorable(descriptorable<super> && o) noexcept {}
    public:     descriptorable<super> & operator=(const descriptorable<super> & o) { return *this; }
    public:     descriptorable<super> & operator=(descriptorable<super> && o) noexcept { return *this; }
    };

}

#endif // __POKEMONISM_DESCRIPTORABLE_HH__