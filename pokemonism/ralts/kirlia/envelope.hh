/**
 * @file            pokemonism/ralts/kirlia/envelope.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_KIRLIA_ENVELOPE_HH__
#define   __POKEMONISM_KIRLIA_ENVELOPE_HH__

#include <pokemonism/pokemon/envelope.hh>

namespace pokemonism {
    namespace kirlia {

        class envelope : public pokemon::envelope {
        public:     typedef pokemon::envelope::message  message;
        public:     inline envelope(void) {}
        public:     inline ~envelope(void) override {}
        public:     envelope(const kirlia::envelope & o) = delete;
        public:     envelope(kirlia::envelope & o) noexcept = delete;
        public:     kirlia::envelope & operator=(const kirlia::envelope & o) = delete;
        public:     kirlia::envelope & operator=(kirlia::envelope & o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_KIRLIA_ENVELOPE_HH__