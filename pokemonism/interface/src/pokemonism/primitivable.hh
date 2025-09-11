/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_PRIMITIVABLE_HH__
#define   __POKEMONISM_PRIMITIVABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class Primitivable {
    public:     inline Primitivable(void);
    public:     inline virtual ~Primitivable(void);
    public:     Primitivable(const Primitivable & o) = delete;
    public:     Primitivable(Primitivable && o) noexcept = delete;
    public:     Primitivable & operator=(const Primitivable & o) = delete;
    public:     Primitivable & operator=(Primitivable && o) noexcept = delete;
    };

    inline Primitivable::Primitivable(void) {

    }

    inline Primitivable::~Primitivable(void) {

    }

}

#endif // __POKEMONISM_PRIMITIVABLE_HH__