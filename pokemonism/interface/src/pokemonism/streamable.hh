/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_STREAMABLE_HH__
#define   __POKEMONISM_STREAMABLE_HH__

#include <pokemonism.hh>
#include <pokemonism/containable.hh>

namespace pokemonism {

    template <class elementable, class super = containable>
    class streamable : public super {
    public:     inline streamable(void);
    public:     inline ~streamable(void) override;
    public:     inline streamable(const streamable<elementable, super> & o);
    public:     inline streamable(streamable<elementable, super> && o) noexcept;
    public:     inline streamable<elementable, super> & operator=(const streamable<elementable, super> & o);
    public:     inline streamable<elementable, super> & operator=(streamable<elementable, super> && o) noexcept;
    };

    template <class elementable, class super>
    inline streamable<elementable, super>::streamable(void) {

    }

    template <class elementable, class super>
    inline streamable<elementable, super>::~streamable(void) {

    }

    template <class elementable, class super>
    inline streamable<elementable, super>::streamable(const streamable<elementable, super> & o) : super(o) {

    }

    template <class elementable, class super>
    inline streamable<elementable, super>::streamable(streamable<elementable, super> && o) noexcept : super(std::move(o)) {

    }

    template <class elementable, class super>
    inline streamable<elementable, super> & streamable<elementable, super>::operator=(const streamable<elementable, super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template <class elementable, class super>
    inline streamable<elementable, super> & streamable<elementable, super>::operator=(streamable<elementable, super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_STREAMABLE_HH__