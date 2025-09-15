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

#include <pokemonism.hh>
#include <pokemonism/containable.hh>

namespace pokemonism {

    template <typename elementable, class super = containable>
    class collectable : public super {
    public:     virtual void add(const elementable & item) = 0;
    public:     virtual void add(elementable && item) = 0;
    // public:     virtual void del(elementable & item) = 0;
    public:     inline collectable(void);
    public:     inline ~collectable(void);
    public:     inline collectable(const collectable<elementable, super> & o);
    public:     inline collectable(collectable<elementable, super> && o) noexcept;
    public:     inline collectable<elementable, super> & operator=(const collectable<elementable, super> & o);
    public:     inline collectable<elementable, super> & operator=(collectable<elementable, super> && o) noexcept;
    };

    template <typename elementable, class super>
    inline collectable<elementable, super>::collectable(void) {

    }

    template <typename elementable, class super>
    inline collectable<elementable, super>::~collectable(void) {

    }

    template <typename elementable, class super>
    inline collectable<elementable, super>::collectable(const collectable<elementable, super> & o) : super(o) {

    }

    template <typename elementable, class super>
    inline collectable<elementable, super>::collectable(collectable<elementable, super> && o) noexcept : super(std::move(o)) {

    }

    template <typename elementable, class super>
    inline collectable<elementable, super> & collectable<elementable, super>::operator=(const collectable<elementable, super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template <typename elementable, class super>
    inline collectable<elementable, super> & collectable<elementable, super>::operator=(collectable<elementable, super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_COLLECTABLE_HH__