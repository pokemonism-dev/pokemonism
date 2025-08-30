/**
 * @file        pokemonism/latios/external/message/format.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @author      Aug 30, 2025
 */

#ifndef   __POKEMONISM_LATIOS_EXTERNAL_MESSAGE_FORMAT__HH__
#define   __POKEMONISM_LATIOS_EXTERNAL_MESSAGE_FORMAT__HH__

#include <pokemonism/primitivable.hh>

namespace pokemonism {
    namespace latios {
        namespace external {
            namespace message {

                class format : public primitivable::object {
                public:     format(void) {}
                public:     ~format(void) override {}
                public:     format(const format & o) = delete;
                public:     format(format && o) noexcept = delete;
                public:     format & operator=(const format & o) = delete;
                public:     format & operator=(format && o) noexcept = delete;
                };
            }
        }
    }
}

#endif // __POKEMONISM_LATIOS_EXTERNAL_MESSAGE_FORMAT__HH__
