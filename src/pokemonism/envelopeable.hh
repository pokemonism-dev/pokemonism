/**
 * @file            pokemonism/envelopeable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_ENVELOPEABLE_HH__
#define   __POKEMONISM_ENVELOPEABLE_HH__

#include <pokemonism/primitivable.hh>

namespace pokemonism {

    template <typename messageable = primitivable>
    class envelopeable {
    public:     typedef messageable message;
    public:     virtual messageable * messageablePop(void) = 0;
    public:     envelopeable(void) {}
    public:     virtual ~envelopeable(void) {}
    public:     envelopeable(const envelopeable<messageable> & o) = delete;
    public:     envelopeable(envelopeable<messageable> && o) noexcept = delete;
    public:     envelopeable<messageable> & operator=(const envelopeable<messageable> & o) = delete;
    public:     envelopeable<messageable> & operator=(envelopeable<messageable> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_ENVELOPEABLE_HH__