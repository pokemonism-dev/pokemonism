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

#include <pokemonism.hh>
#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class elementable, class super = virtualable>
    class continuable : public super {
    public:     virtual unsigned long capacityCal(unsigned long n) = 0;
    public:     virtual void set(const elementable & item, unsigned long n) = 0;
    public:     virtual void set(const elementable * source, unsigned long sourceLen) = 0;
    public:     virtual void cat(const elementable & item, unsigned long n) = 0;
    public:     virtual void cat(const elementable * source, unsigned long sourceLen) = 0;
    public:     inline continuable(void);
    public:     inline ~continuable(void) override;
    public:     inline continuable(const continuable<elementable, super> & o);
    public:     inline continuable(continuable<elementable, super> && o) noexcept;
    public:     inline continuable<elementable, super> & operator=(const continuable<elementable, super> & o);
    public:     inline continuable<elementable, super> & operator=(continuable<elementable, super> && o) noexcept;
    };

    template <class elementable, class super>
    inline continuable<elementable, super>::continuable(void) {

    }

    template <class elementable, class super>
    inline continuable<elementable, super>::~continuable(void) {

    }

    template <class elementable, class super>
    inline continuable<elementable, super>::continuable(const continuable<elementable, super> & o) : super(o) {

    }

    template <class elementable, class super>
    inline continuable<elementable, super>::continuable(continuable<elementable, super> && o) noexcept : super(std::move(o)) {

    }

    template <class elementable, class super>
    inline continuable<elementable, super> & continuable<elementable, super>::operator=(const continuable<elementable, super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template <class elementable, class super>
    inline continuable<elementable, super> & continuable<elementable, super>::operator=(continuable<elementable, super> && o) noexcept {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

}

#endif // __POKEMONISM_CONTINUABLE_HH__