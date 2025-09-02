/**
 * @file            pokemonism/ralts/kirlia/gardevoir/subscription.cc
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#include <pokemonism/pokemon/exception.hh>

#include "subscription.hh"

#include <pokemonism/ralts/kirlia/gallade/engine.hh>
#include <pokemonism/ralts/kirlia/gallade/subscription.hh>

namespace pokemonism {
    namespace gardevoir {
        bool subscription::cancel(void) {
            if (internal != nullptr) {
                if (internal->check(gallade::subscription::state::reg) != gallade::subscription::state::none) {
                    internal = gallade::engine::del(internal);
                    return true;
                }
            }
            return false;
        }

        subscription::~subscription(void) {
            internal = gallade::engine::rel(internal);
        }
    }
}