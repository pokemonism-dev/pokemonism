/**
 * @file            pokemonism/cloneable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_CLONEABLE_HH__
#define   __POKEMONISM_CLONEABLE_HH__

namespace pokemonism {

    class cloneable {
    public:     virtual cloneable * clone(void) const = 0;
    public:     cloneable(void) {}
    public:     virtual ~cloneable(void) {}
    public:     cloneable(const cloneable & o) = delete;
    public:     cloneable(cloneable && o) noexcept = delete;
    public:     cloneable & operator=(const cloneable & o) = delete;
    public:     cloneable & operator=(cloneable && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_CLONEABLE_HH__