/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_VIRTUALABLE_HH__
#define   __POKEMONISM_VIRTUALABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class Virtualable {
    public:     Virtualable(void);
    public:     virtual ~Virtualable(void);
    public:     Virtualable(const Virtualable & o) = delete;
    public:     Virtualable(Virtualable && o) noexcept = delete;
    public:     Virtualable & operator=(const Virtualable & o) = delete;
    public:     Virtualable & operator=(Virtualable && o) noexcept = delete;
    };

    inline Virtualable::Virtualable(void) {

    }

    inline Virtualable::~Virtualable(void) {

    }


}

#endif // __POKEMONISM_VIRTUALABLE_HH__