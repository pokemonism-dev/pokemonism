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

namespace pokemonism {

    class virtualable {
    public:     inline virtualable(void);
    public:     inline virtual ~virtualable(void);
    public:     inline virtualable(const virtualable & o);
    public:     inline virtualable(virtualable && o) noexcept;
    public:     inline virtualable & operator=(const virtualable & o);
    public:     inline virtualable & operator=(virtualable && o) noexcept;
    };

    inline virtualable::virtualable(void) {

    }

    inline virtualable::~virtualable(void) {

    }

    inline virtualable::virtualable(const virtualable & o) {

    }

    inline virtualable::virtualable(virtualable && o) noexcept {

    }

    inline virtualable & virtualable::operator=(const virtualable & o) {
        return *this;
    }

    inline virtualable & virtualable::operator=(virtualable && o) noexcept {
        return *this;
    }


}

#endif // __POKEMONISM_VIRTUALABLE_HH__