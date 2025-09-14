/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_OBSERVABLE_HH__
#define   __POKEMONISM_OBSERVABLE_HH__

#include <pokemonism/virtualable.hh>
#include <pokemonism/observerable.hh>

namespace pokemonism {

    template <typename element, class observer = observerable<element>, class super = virtualable>
    class observable : public super {
    public:     virtual observer * subscribe(observer * o) = 0;
    public:     inline observable(void);
    public:     inline virtual ~observable(void);
    public:     inline observable(const observable<element, observer, super> & o);
    public:     inline observable(observable<element, observer, super> && o) noexcept;
    public:     inline observable<element, observer, super> & operator=(const observable<element, observer, super> & o);
    public:     inline observable<element, observer, super> & operator=(observable<element, observer, super> && o) noexcept;
    };

    template <typename element, class observer, class super>
    observable<element, observer, super>::observable(void) {

    }

    template <typename element, class observer, class super>
    observable<element, observer, super>::~observable(void) {

    }

    template <typename element, class observer, class super>
    inline observable<element, observer, super>::observable(const observable<element, observer, super> & o) : super(o) {

    }

    template <typename element, class observer, class super>
    inline observable<element, observer, super>::observable(observable<element, observer, super> && o) noexcept : super(std::move(o)) {

    }

    template <typename element, class observer, class super>
    inline observable<element, observer, super> & observable<element, observer, super>::operator=(const observable<element, observer, super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template <typename element, class observer, class super>
    inline observable<element, observer, super> & observable<element, observer, super>::operator=(observable<element, observer, super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_OBSERVABLE_HH__