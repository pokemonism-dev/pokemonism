/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_CONTINUABLE_HH__
#define   __POKEMONISM_CONTINUABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class Elementable, class Super = Virtualable>
    class Continuable : public Super {
    public:     virtual unsigned long capacityCal(unsigned long n) = 0;
    public:     virtual void set(const Elementable & item, unsigned long n) = 0;
    public:     virtual void set(const Elementable * source, unsigned long sourceLen) = 0;
    public:     virtual void cat(const Elementable & item, unsigned long n) = 0;
    public:     virtual void cat(const Elementable * source, unsigned long sourceLen) = 0;
    public:     inline Continuable(void);
    public:     inline ~Continuable(void) override;
    public:     inline Continuable(const Continuable<Elementable, Super> & o);
    public:     inline Continuable(Continuable<Elementable, Super> && o) noexcept;
    public:     inline Continuable<Elementable, Super> & operator=(const Continuable<Elementable, Super> & o);
    public:     inline Continuable<Elementable, Super> & operator=(Continuable<Elementable, Super> && o) noexcept;
    };

    template <class Elementable, class Super>
    inline Continuable<Elementable, Super>::Continuable(void) {

    }

    template <class Elementable, class Super>
    inline Continuable<Elementable, Super>::~Continuable(void) {

    }

    template <class Elementable, class Super>
    inline Continuable<Elementable, Super>::Continuable(const Continuable<Elementable, Super> & o) : Super(o) {

    }

    template <class Elementable, class Super>
    inline Continuable<Elementable, Super>::Continuable(Continuable<Elementable, Super> && o) noexcept : Super(std::move(o)) {

    }

    template <class Elementable, class Super>
    inline Continuable<Elementable, Super> & Continuable<Elementable, Super>::operator=(const Continuable<Elementable, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template <class Elementable, class Super>
    inline Continuable<Elementable, Super> & Continuable<Elementable, Super>::operator=(Continuable<Elementable, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

}

#endif // __POKEMONISM_CONTINUABLE_HH__