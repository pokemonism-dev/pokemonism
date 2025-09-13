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

namespace pokemonism {

    class Primitivable {
    public:     inline Primitivable(void);
    public:     inline virtual ~Primitivable(void);
    public:     inline Primitivable(const Primitivable & o);
    public:     inline Primitivable(Primitivable && o) noexcept;
    public:     inline Primitivable & operator=(const Primitivable & o);
    public:     inline Primitivable & operator=(Primitivable && o) noexcept;
    };

    inline Primitivable::Primitivable(void) {

    }

    inline Primitivable::~Primitivable(void) {

    }

    inline Primitivable::Primitivable(const Primitivable & o) {

    }

    inline Primitivable::Primitivable(Primitivable && o) noexcept {

    }

    inline Primitivable & Primitivable::operator=(const Primitivable & o) {
        return *this;
    }

    inline Primitivable & Primitivable::operator=(Primitivable && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_PRIMITIVABLE_HH__