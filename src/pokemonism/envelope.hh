/**
 * @file            pokemonism/envelope.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_ENVELOPE_HH__
#define   __POKEMONISM_ENVELOPE_HH__

#include <pokemonism/interface/envelopeable.hh>

namespace pokemonism {

    template <typename messageable = primitivable>
    class envelope : public envelopeable<messageable> {
    public:     envelope(void) {}
    public:     ~envelope(void) override {}
    public:     envelope(const envelope<messageable> & o) = delete;
    public:     envelope(envelope<messageable> && o) noexcept = delete;
    public:     envelope<messageable> & operator=(const envelope<messageable> & o) = delete;
    public:     envelope<messageable> & operator=(envelope<messageable> && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_ENVELOPE_HH__