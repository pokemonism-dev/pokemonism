/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_CLONEABLE_HH__
#define   __POKEMONISM_CLONEABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class Super = Virtualable>
    class Cloneable : public Super {
    public:     virtual Cloneable<Super> * clone(void) const = 0;
    public:     inline Cloneable(void);
    public:     inline ~Cloneable(void) override;
    public:     inline Cloneable(const Cloneable<Super> & o);
    public:     inline Cloneable(Cloneable<Super> && o) noexcept;
    public:     inline Cloneable<Super> & operator=(const Cloneable<Super> & o);
    public:     inline Cloneable<Super> & operator=(Cloneable<Super> && o) noexcept;
    };

    template<class Super>
    inline Cloneable<Super>::Cloneable(void) {

    }

    template<class Super>
    inline Cloneable<Super>::~Cloneable(void) {

    }

    template<class Super>
    inline Cloneable<Super>::Cloneable(const Cloneable<Super> & o) : Super(o) {

    }

    template<class Super>
    inline Cloneable<Super>::Cloneable(Cloneable<Super> && o) noexcept : Super(std::move(o)) {

    }

    template<class Super>
    inline Cloneable<Super> & Cloneable<Super>::operator=(const Cloneable<Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template<class Super>
    inline Cloneable<Super> & Cloneable<Super>::operator=(Cloneable<Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_CLONEABLE_HH__