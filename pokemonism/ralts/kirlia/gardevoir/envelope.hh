/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_ENVELOPE_HH__
#define   __POKEMONISM_GARDEVOIR_ENVELOPE_HH__

#include <pokemonism/ralts/kirlia/envelope.hh>

namespace pokemonism {
    namespace gardevoir {

        class envelope : public kirlia::envelope {
        public:     typedef kirlia::envelope::message  message;
        public:     inline envelope(void) {}
        public:     inline ~envelope(void) override {}
        public:     envelope(const gardevoir::envelope & o) = delete;
        public:     envelope(gardevoir::envelope & o) noexcept = delete;
        public:     gardevoir::envelope & operator=(const gardevoir::envelope & o) = delete;
        public:     gardevoir::envelope & operator=(gardevoir::envelope & o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_GARDEVOIR_ENVELOPE_HH__