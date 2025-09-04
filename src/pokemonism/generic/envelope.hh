/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_GENERIC_ENVELOPE_HH__
#define   __POKEMONISM_GENERIC_ENVELOPE_HH__

#include <pokemonism/envelopeable.hh>

namespace pokemonism {
    namespace generic {

        template <typename messageable = primitivable>
        class envelope : public virtual envelopeable {
        public:     typedef messageable     message;
        public:     message * messagePop(void) override = 0;
        public:     envelope(void) {}
        public:     ~envelope(void) override {}
        public:     envelope(const envelope<messageable> & o) = delete;
        public:     envelope(envelope<messageable> && o) noexcept = delete;
        public:     envelope<messageable> & operator=(const envelope<messageable> & o) = delete;
        public:     envelope<messageable> & operator=(envelope<messageable> && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_GENERIC_ENVELOPE_HH__