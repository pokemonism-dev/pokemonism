/**
 * @file            pokemonism/interface/envelopeable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_ENVELOPEABLE_HH__
#define   __POKEMONISM_INTERFACE_ENVELOPEABLE_HH__

#include <pokemonism/interface/primitivable.hh>

namespace pokemonism {
    namespace interface {
        template <typename messageable = primitivable>
        class envelopeable {
        public:     virtual messageable * messagePop(void) = 0;
        public:     virtual messageable * messageGet(void) = 0;
        public:     envelopeable(void) {}
        public:     virtual ~envelopeable(void) {}
        public:     envelopeable(const envelopeable<messageable> & o) = delete;
        public:     envelopeable(envelopeable<messageable> && o) noexcept = delete;
        public:     envelopeable<messageable> & operator=(const envelopeable<messageable> & o) = delete;
        public:     envelopeable<messageable> & operator=(envelopeable<messageable> && o) noexcept = delete;
        };
    }

    template <typename messageable = primitivable> using envelopeable = interface::envelopeable<messageable>;
}

#endif // __POKEMONISM_INTERFACE_ENVELOPEABLE_HH__
