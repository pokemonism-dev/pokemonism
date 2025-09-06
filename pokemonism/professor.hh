/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_PROFESSOR_HH__
#define   __POKEMONISM_PROFESSOR_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class professor {
    public:     professor(void) {}
    public:     virtual ~professor(void) {}
    public:     professor(const professor & o) = delete;
    public:     professor(professor && o) noexcept = delete;
    public:     professor & operator=(const professor & o) = delete;
    public:     professor & operator=(professor && o) noexcept = delete;
    };

    /**
     * oak::get<pokemon::command::randomizer>()
     * oak::gen<
     */

}

#endif // __POKEMONISM_PROFESSOR_HH__