/**
 * @file        pokemonism/mareep/observable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_MAREEP_OBSERVABLE__HH__
#define   __POKEMONISM_MAREEP_OBSERVABLE__HH__

#include <pokemon.hh>

namespace pokemonism {
    namespace mareep {

        template <class element> class observer;
        class subscription;

        template <class element>
        class observable {
        public:     virtual mareep::subscription * subscribe(mareep::observer<element> * o) = 0;
        public:     virtual mareep::subscription * subscribe(const mareep::observer<element> & o) = 0;
        public:     virtual mareep::subscription * subscribe(const mareep::observer<element> && o) = 0;
        public:     observable(void) {}
        public:     virtual ~observable(void) {}
        public:     observable(const observable<element> & o) = delete;
        public:     observable(observable<element> & o) noexcept = delete;
        public:     observable<element> & operator=(const observable<element> & o) = delete;
        public:     observable<element> & operator=(observable <element>& o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_MAREEP_OBSERVABLE__HH__
