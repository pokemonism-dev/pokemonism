/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_APPLICATIONABLE_HH__
#define   __POKEMONISM_APPLICATIONABLE_HH__

#include <pokemonism/virtualable.hh>
#include <pokemonism/runnable.hh>

namespace pokemonism {

    class Applicationable : public Runnable<Virtualable> {
    public:     virtual const char * platformNameGet(void) const noexcept = 0;
    public:     inline Applicationable(void);
    public:     inline ~Applicationable(void) override;
    public:     Applicationable(const Applicationable & o) = delete;
    public:     Applicationable(Applicationable && o) noexcept = delete;
    public:     Applicationable & operator=(const Applicationable & o) = delete;
    public:     Applicationable & operator=(Applicationable && o) noexcept = delete;
    };

    Applicationable::Applicationable(void) {

    }

    Applicationable::~Applicationable(void) {

    }

}

#endif // __POKEMONISM_APPLICATIONABLE_HH__