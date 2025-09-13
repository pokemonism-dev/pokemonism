/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_CONTAINABLE_HH__
#define   __POKEMONISM_CONTAINABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    class Containable : public Virtualable {
    public:     virtual void clear(void) = 0;
    public:     inline Containable(void);
    public:     inline ~Containable(void) override;
    public:     inline Containable(const Containable & o);
    public:     inline Containable(Containable && o) noexcept;
    public:     inline Containable & operator=(const Containable & o);
    public:     inline Containable & operator=(Containable && o) noexcept;
    };

    inline Containable::Containable(void) {

    }

    inline Containable::~Containable(void) {

    }

    inline Containable::Containable(const Containable & o) {

    }

    inline Containable::Containable(Containable && o) noexcept {

    }

    inline Containable & Containable::operator=(const Containable & o) {
        return *this;
    }

    inline Containable & Containable::operator=(Containable && o) noexcept {
        return *this;
    }


}

#endif // __POKEMONISM_CONTAINABLE_HH__