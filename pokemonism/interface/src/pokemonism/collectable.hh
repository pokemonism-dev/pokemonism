/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_COLLECTABLE_HH__
#define   __POKEMONISM_COLLECTABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {
    /**
     * 리턴 값에 대해서 고민해보자... 리턴 값은 무엇인가?
     *
     *
     * @tparam Element
     * @tparam Super
     */
    template <typename Element, class Super = Virtualable>
    class Collectable : public Super {
    public:     virtual void add(const Element & item) = 0;
    public:     virtual void add(Element && item) = 0;
    public:     virtual void del(const Element & item) = 0;
    public:     inline Collectable(void);
    public:     inline ~Collectable(void);
    public:     Collectable(const Collectable<Element, Super> & o) = delete;
    public:     Collectable(Collectable<Element, Super> && o) noexcept = delete;
    public:     Collectable<Element, Super> & operator=(const Collectable<Element, Super> & o) = delete;
    public:     Collectable<Element, Super> & operator=(Collectable<Element, Super> && o) noexcept = delete;
    };

    template <typename Element, class Super>
    inline Collectable<Element, Super>::Collectable(void) {

    }

    template <typename Element, class Super>
    inline Collectable<Element, Super>::~Collectable(void) {

    }

}

#endif // __POKEMONISM_COLLECTABLE_HH__