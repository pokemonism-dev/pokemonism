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
    public:     inline Containable(void);
    public:     inline ~Containable(void) override;
    public:     Containable(const Containable & o) = delete;
    public:     Containable(Containable && o) noexcept = delete;
    public:     Containable & operator=(const Containable & o) = delete;
    public:     Containable & operator=(Containable && o) noexcept = delete;
    };

    inline Containable::Containable(void) {

    }

    inline Containable::~Containable(void) {

    }


}

#endif // __POKEMONISM_CONTAINABLE_HH__