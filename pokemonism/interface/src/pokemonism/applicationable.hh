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
    protected:  static Applicationable * singleton;
    public:     virtual const char * platformNameGet(void) const noexcept = 0;
    protected:  int run(void) override = 0;
    public:     inline Applicationable(void);
    public:     inline ~Applicationable(void) override;
    public:     inline Applicationable(const Applicationable & o);
    public:     inline Applicationable(Applicationable && o) noexcept;
    public:     inline Applicationable & operator=(const Applicationable & o);
    public:     inline Applicationable & operator=(Applicationable && o) noexcept;
    };

    Applicationable::Applicationable(void) {

    }

    Applicationable::~Applicationable(void) {

    }

    inline Applicationable::Applicationable(const Applicationable & o) : Runnable<Virtualable>(o) {

    }

    inline Applicationable::Applicationable(Applicationable && o) noexcept : Runnable<Virtualable>(std::move(o)) {

    }

    inline Applicationable & Applicationable::operator=(const Applicationable & o) {
        if (pointof(o) != this) Runnable<Virtualable>::operator=(o);
        return *this;
    }

    inline Applicationable & Applicationable::operator=(Applicationable && o) noexcept {
        if (pointof(o) != this) Runnable<Virtualable>::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_APPLICATIONABLE_HH__