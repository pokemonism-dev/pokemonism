/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#include <pokemonism/ralts/kirlia/engine.hh>

using namespace pokemonism;

namespace pokemonism {
    namespace persian {
        inline void terminator(void) {}
    }
}

int main(int argc, char ** argv) {
    kirlia::engine::on();
    // kirlia::engine::

    kirlia::engine::off(persian::terminator);

    return kirlia::engine::run();
}
