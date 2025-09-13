/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_ENVELOPEABLE_HH__
#define   __POKEMONISM_ENVELOPEABLE_HH__

#include <pokemonism/virtualable.hh>
#include <pokemonism/primitivable.hh>

namespace pokemonism {

    template <class Super>
    class Envelopeable : public Super {
    public:     virtual Primitivable * messagePop(void) = 0;
    public:     inline Envelopeable(void);
    public:     inline ~Envelopeable(void) override;
    public:     inline Envelopeable(const Envelopeable<Super> & o);
    public:     inline Envelopeable(Envelopeable<Super> && o) noexcept;
    public:     inline Envelopeable<Super> & operator=(const Envelopeable<Super> & o);
    public:     inline Envelopeable<Super> & operator=(Envelopeable<Super> && o) noexcept;
    };

    template<class Super>
    inline Envelopeable<Super>::Envelopeable(void) {

    }

    template<class Super>
    inline Envelopeable<Super>::~Envelopeable(void) {

    }

    template<class Super>
    inline Envelopeable<Super>::Envelopeable(const Envelopeable<Super> & o) : Super(o) {

    }

    template<class Super>
    inline Envelopeable<Super>::Envelopeable(Envelopeable<Super> && o) noexcept : Super(std::move(o)) {

    }

    template<class Super>
    inline Envelopeable<Super> & Envelopeable<Super>::operator=(const Envelopeable<Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template<class Super>
    inline Envelopeable<Super> & Envelopeable<Super>::operator=(Envelopeable<Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_ENVELOPEABLE_HH__