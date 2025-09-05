/**
 * @file        pokemonism/mareep/observer.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_MAREEP_OBSERVER__HH__
#define   __POKEMONISM_MAREEP_OBSERVER__HH__

namespace pokemonism {
    namespace mareep {
        template <class element>
        class observer {
        public:     observer(void) {}
        public:     virtual ~observer(void) {}
        public:     observer(const observer<element> & o) {}
        public:     observer(observer<element> & o) noexcept {}
        public:     observer<element> & operator=(const observer<element> & o) { return *this; }
        public:     observer<element> & operator=(observer<element> & o) noexcept { return *this; }
        };
    }
}

#endif // __POKEMONISM_MAREEP_OBSERVER__HH__
