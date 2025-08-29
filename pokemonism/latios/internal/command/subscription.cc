/**
 * @file        pokemonism/latios/internal/subscription.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#include "subscription.hh"

/**
 * @file        pokemonism/latios/internal/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#include "subscription.hh"

#include "event.hh"

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace command {

                subscription::subscription(pokemonism::command * target, uint32 properties, const callback * callbacks, uint32 n) :
                internal::pack<pokemonism::command, pokemonism::command, pokemonism::command>::subscription(target, properties, reinterpret_cast<const internal::pack<pokemonism::command, pokemonism::command, pokemonism::command>::subscription::callback *>(callbacks), n) {

                }

                // class event;
                //
                // class subscription : public internal::pack<pokemonism::command, pokemonism::command, pokemonism::command>::subscription {
                // public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *);
                // public:     subscription(pokemonism::command * target, uint32 properties, const callback * callbacks, uint32 n);
                //
                // };

            }

        }
    }
}

