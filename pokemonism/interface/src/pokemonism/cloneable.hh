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

#include <pokemonism.hh>
#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class super = virtualable>
    class cloneable : public super {
    public:     virtual cloneable<super> * clone(void) const = 0;
    public:     inline cloneable(void);
    public:     inline ~cloneable(void) override;
    public:     inline cloneable(const cloneable<super> & o);
    public:     inline cloneable(cloneable<super> && o) noexcept;
    public:     inline cloneable<super> & operator=(const cloneable<super> & o);
    public:     inline cloneable<super> & operator=(cloneable<super> && o) noexcept;
    };

    template<class super>
    inline cloneable<super>::cloneable(void) {

    }

    template<class super>
    inline cloneable<super>::~cloneable(void) {

    }

    template<class super>
    inline cloneable<super>::cloneable(const cloneable<super> & o) : super(o) {

    }

    template<class super>
    inline cloneable<super>::cloneable(cloneable<super> && o) noexcept : super(std::move(o)) {

    }

    template<class super>
    inline cloneable<super> & cloneable<super>::operator=(const cloneable<super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template<class super>
    inline cloneable<super> & cloneable<super>::operator=(cloneable<super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_CLONEABLE_HH__