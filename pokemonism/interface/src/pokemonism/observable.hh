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

namespace pokemonism {

    template <typename Element>
    class Observable {
    public:     inline Observable(void);
    public:     inline virtual ~Observable(void);
    public:     Observable(const Observable<Element> & o) = delete;
    public:     Observable(Observable<Element> && o) noexcept = delete;
    public:     Observable<Element> & operator=(const Observable<Element> & o) = delete;
    public:     Observable<Element> & operator=(Observable<Element> && o) noexcept = delete;
    };

    template <typename Element>
    Observable<Element>::Observable(void) {

    }

    template <typename Element>
    Observable<Element>::~Observable(void) {

    }


}

#endif // __POKEMONISM_OBSERVABLE_HH__