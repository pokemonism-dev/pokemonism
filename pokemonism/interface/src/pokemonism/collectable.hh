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

#include <pokemonism/containable.hh>

namespace pokemonism {

    template <typename Elementable, class Super = Containable>
    class Collectable : public Super {
    public:     virtual void add(const Elementable & item) = 0;
    public:     virtual void add(Elementable && item) = 0;
    public:     virtual void del(const Elementable & item) = 0;
    public:     inline Collectable(void);
    public:     inline ~Collectable(void);
    public:     inline Collectable(const Collectable<Elementable, Super> & o);
    public:     inline Collectable(Collectable<Elementable, Super> && o) noexcept;
    public:     inline Collectable<Elementable, Super> & operator=(const Collectable<Elementable, Super> & o);
    public:     inline Collectable<Elementable, Super> & operator=(Collectable<Elementable, Super> && o) noexcept;
    };

    template <typename Elementable, class Super>
    inline Collectable<Elementable, Super>::Collectable(void) {

    }

    template <typename Elementable, class Super>
    inline Collectable<Elementable, Super>::~Collectable(void) {

    }

    template <typename Elementable, class Super>
    inline Collectable<Elementable, Super>::Collectable(const Collectable<Elementable, Super> & o) : Super(o) {

    }

    template <typename Elementable, class Super>
    inline Collectable<Elementable, Super>::Collectable(Collectable<Elementable, Super> && o) noexcept : Super(std::move(o)) {

    }

    template <typename Elementable, class Super>
    inline Collectable<Elementable, Super> & Collectable<Elementable, Super>::operator=(const Collectable<Elementable, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template <typename Elementable, class Super>
    inline Collectable<Elementable, Super> & Collectable<Elementable, Super>::operator=(Collectable<Elementable, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_COLLECTABLE_HH__