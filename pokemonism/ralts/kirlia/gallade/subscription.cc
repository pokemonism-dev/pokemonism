/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#include <pokemonism/ralts/kirlia/gardevoir/subscription.hh>

#include "subscription.hh"

namespace pokemonism {
    namespace gallade {
        bool subscription::cancel(void) {
            if (internal != nullptr) {
                if (internal->check(gardevoir::subscription::state::reg) != gardevoir::subscription::state::none) {
                    internal->cancel();
                    return true;
                }
            }
            return false;
        }

        subscription::~subscription(void) {
            internal = allocator::del(internal);
        }
    }
}