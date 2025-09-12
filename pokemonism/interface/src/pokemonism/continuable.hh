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

    template <class Element, class Super = Virtualable>
    class Continuable {
    public:     inline Continuable(void);
    public:     inline ~Continuable(void);
    public:     Continuable(const Continuable<Element, Super> & o) = delete;
    public:     Continuable(Continuable<Element, Super> && o) noexcept = delete;
    public:     Continuable<Element, Super> & operator=(const Continuable<Element, Super> & o) = delete;
    public:     Continuable<Element, Super> & operator=(Continuable<Element, Super> && o) noexcept = delete;
    };

    template <class Element, class Super>
    inline Continuable<Element, Super>::Continuable(void) {

    }

    template <class Element, class Super>
    inline Continuable<Element, Super>::~Continuable(void) {

    }

}

#endif // __POKEMONISM_CONTINUABLE_HH__