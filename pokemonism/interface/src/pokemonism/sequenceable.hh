/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_SEQUENCEABLE_HH__
#define   __POKEMONISM_SEQUENCEABLE_HH__

#include <pokemonism.hh>
#include <pokemonism/containable.hh>

namespace pokemonism {

    template <class elementable, class super = containable>
    class sequenceable : public super {
    public:     inline sequenceable(void);
    public:     inline ~sequenceable(void) override;
    public:     inline sequenceable(const sequenceable<elementable, super> & o);
    public:     inline sequenceable(sequenceable<elementable, super> && o) noexcept;
    public:     inline sequenceable<elementable, super> & operator=(const sequenceable<elementable, super> & o);
    public:     inline sequenceable<elementable, super> & operator=(sequenceable<elementable, super> && o) noexcept;
    };

    template <class elementable, class super>
    inline sequenceable<elementable, super>::sequenceable(void) {

    }

    template <class elementable, class super>
    inline sequenceable<elementable, super>::~sequenceable(void) {

    }

    template <class elementable, class super>
    inline sequenceable<elementable, super>::sequenceable(const sequenceable<elementable, super> & o) : super(o) {

    }

    template <class elementable, class super>
    inline sequenceable<elementable, super>::sequenceable(sequenceable<elementable, super> && o) noexcept : super(std::move(o)) {

    }

    template <class elementable, class super>
    inline sequenceable<elementable, super> & sequenceable<elementable, super>::operator=(const sequenceable<elementable, super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template <class elementable, class super>
    inline sequenceable<elementable, super> & sequenceable<elementable, super>::operator=(sequenceable<elementable, super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_SEQUENCEABLE_HH__