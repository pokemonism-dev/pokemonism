/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_COMMAND_HH__
#define   __POKEMONISM_WATTREL_COMMAND_HH__

#include <pokemonism.hh>

#include <pokemonism/wattrel/generator.hh>

namespace pokemonism {
    namespace wattrel {
        namespace command {
            class generator : public wattrel::generator {
            public:     generator(void) {}
            public:     ~generator(void) override {}
            public:     generator(const generator & o) = delete;
            public:     generator(generator && o) noexcept = delete;
            public:     generator & operator=(const generator & o) = delete;
            public:     generator & operator=(generator && o) noexcept = delete;
            };
        }
    }
}

#endif // __POKEMONISM_WATTREL_COMMAND_HH__
