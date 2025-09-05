/**
 * @file            pokemonism/supporter.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 5, 2025
 */

#ifndef   __POKEMONISM_SUPPORTER_HH__
#define   __POKEMONISM_SUPPORTER_HH__

#include <pokemonism/item.hh>
#include <pokemonism/pokemon.hh>

namespace pokemonism {

    class supporter {
    public:     virtual void capture(pokemon * mon) = 0;
    public:     virtual pokemon * evolve(pokemon * mon) = 0;
    public:     virtual pokemon * evolve(pokemon * mon, item * item) = 0;
    public:     supporter(void) {}
    public:     virtual ~supporter(void) {}
    public:     supporter(const supporter & o) = delete;
    public:     supporter(supporter && o) noexcept = delete;
    public:     supporter & operator=(const supporter & o) = delete;
    public:     supporter & operator=(supporter && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SUPPORTER_HH__