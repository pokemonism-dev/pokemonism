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
    public:     Cloneable(const Cloneable<Super> & o) = delete;
    public:     Cloneable(Cloneable<Super> && o) noexcept = delete;
    public:     Cloneable<Super> & operator=(const Cloneable<Super> & o) = delete;
    public:     Cloneable<Super> & operator=(Cloneable<Super> && o) noexcept = delete;
    };

    template<class Super>
    inline Cloneable<Super>::Cloneable(void) {

    }

    template<class Super>
    inline Cloneable<Super>::~Cloneable(void) {

    }


}

#endif // __POKEMONISM_CLONEABLE_HH__