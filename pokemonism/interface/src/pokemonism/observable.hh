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

    template <typename Element, class Observer = Observerable<Element>, class Super = Virtualable>
    class Observable : public Super {
    public:     virtual Observer * subscribe(Observer * o) = 0;
    public:     inline Observable(void);
    public:     inline virtual ~Observable(void);
    public:     inline Observable(const Observable<Element, Observer, Super> & o);
    public:     inline Observable(Observable<Element, Observer, Super> && o) noexcept;
    public:     inline Observable<Element, Observer, Super> & operator=(const Observable<Element, Observer, Super> & o);
    public:     inline Observable<Element, Observer, Super> & operator=(Observable<Element, Observer, Super> && o) noexcept;
    };

    template <typename Element, class Observer, class Super>
    Observable<Element, Observer, Super>::Observable(void) {

    }

    template <typename Element, class Observer, class Super>
    Observable<Element, Observer, Super>::~Observable(void) {

    }

    template <typename Element, class Observer, class Super>
    inline Observable<Element, Observer, Super>::Observable(const Observable<Element, Observer, Super> & o) : Super(o) {

    }

    template <typename Element, class Observer, class Super>
    inline Observable<Element, Observer, Super>::Observable(Observable<Element, Observer, Super> && o) noexcept : Super(std::move(o)) {

    }

    template <typename Element, class Observer, class Super>
    inline Observable<Element, Observer, Super> & Observable<Element, Observer, Super>::operator=(const Observable<Element, Observer, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template <typename Element, class Observer, class Super>
    inline Observable<Element, Observer, Super> & Observable<Element, Observer, Super>::operator=(Observable<Element, Observer, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_OBSERVABLE_HH__