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

    /**
     * 가상 함수
     */
    class Virtualable {
    public:     inline Virtualable(void);
    public:     inline virtual ~Virtualable(void);
    public:     inline Virtualable(const Virtualable & o);
    public:     inline Virtualable(Virtualable && o) noexcept;
    public:     inline Virtualable & operator=(const Virtualable & o);
    public:     inline Virtualable & operator=(Virtualable && o) noexcept;
    };

    inline Virtualable::Virtualable(void) {

    }

    inline Virtualable::~Virtualable(void) {

    }

    inline Virtualable::Virtualable(const Virtualable & o) {

    }

    inline Virtualable::Virtualable(Virtualable && o) noexcept {

    }

    inline Virtualable & Virtualable::operator=(const Virtualable & o) {
        return *this;
    }

    inline Virtualable & Virtualable::operator=(Virtualable && o) noexcept {
        return *this;
    }


}

#endif // __POKEMONISM_VIRTUALABLE_HH__