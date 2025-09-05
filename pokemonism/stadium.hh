/**
 * @file            pokemonism/stadium.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 5, 2025
 */

#ifndef   __POKEMONISM_STADIUM_HH__
#define   __POKEMONISM_STADIUM_HH__

#include <pokemonism.hh>

namespace pokemonism {
    class stadium {
    public:     stadium(void) {}
    public:     virtual ~stadium(void) {}
    public:     stadium(const stadium & o) = delete;
    public:     stadium(stadium && o) = delete;
    public:     stadium & operator=(const stadium & o) = delete;
    public:     stadium & operator=(stadium && o) = delete;
    };
}

#endif // __POKEMONISM_STADIUM_HH__