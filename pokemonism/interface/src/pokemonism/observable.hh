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
    public:     Observable(const Observable<Element, Observer, Super> & o) = delete;
    public:     Observable(Observable<Element, Observer, Super> && o) noexcept = delete;
    public:     Observable<Element, Observer, Super> & operator=(const Observable<Element, Observer, Super> & o) = delete;
    public:     Observable<Element, Observer, Super> & operator=(Observable<Element, Observer, Super> && o) noexcept = delete;
    };

    template <typename Element, class Observer, class Super>
    Observable<Element, Observer, Super>::Observable(void) {

    }

    template <typename Element, class Observer, class Super>
    Observable<Element, Observer, Super>::~Observable(void) {

    }


}

#endif // __POKEMONISM_OBSERVABLE_HH__