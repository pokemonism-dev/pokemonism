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
    public:     Collectable(const Collectable<Elementable, Super> & o) = delete;
    public:     Collectable(Collectable<Elementable, Super> && o) noexcept = delete;
    public:     Collectable<Elementable, Super> & operator=(const Collectable<Elementable, Super> & o) = delete;
    public:     Collectable<Elementable, Super> & operator=(Collectable<Elementable, Super> && o) noexcept = delete;
    };

    template <typename Elementable, class Super>
    inline Collectable<Elementable, Super>::Collectable(void) {

    }

    template <typename Elementable, class Super>
    inline Collectable<Elementable, Super>::~Collectable(void) {

    }

}

#endif // __POKEMONISM_COLLECTABLE_HH__