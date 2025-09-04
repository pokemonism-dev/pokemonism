/**
 * @file            pokemonism/envelope.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_ENVELOPE_HH__
#define   __POKEMONISM_ENVELOPE_HH__

#include <pokemonism/envelopeable.hh>

namespace pokemonism {

    template <typename messageable = primitivable>
    class envelope : public envelopeable<messageable> {
    public:     typedef envelopeable<messageable>::message  message;
    public:     envelope(void) {}
    public:     ~envelope(void) override {}
    public:     envelope(const envelope<messageable> & o) = delete;
    public:     envelope(envelope<messageable> && o) noexcept = delete;
    public:     envelope<messageable> & operator=(const envelope<messageable> & o) = delete;
    public:     envelope<messageable> & operator=(envelope<messageable> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_ENVELOPE_HH__