/**
 * @file        latios/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_LATIOS_ENGINE__HH__
#define   __POKEMONISM_LATIOS_ENGINE__HH__

#include <pokemon.hh>

namespace pokemonism {
    namespace latios {

        namespace external {
            class engine;
        }

        class engine : public pokemonism::object {
        public:     static int on(void (*bootstrap)(pokemonism::latios::external::engine &));
        public:     static int run(void);
        public:     engine(void);
        public:     ~engine(void) override;
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };

    }

    using engine = latios::engine;

}

#endif // __POKEMONISM_LATIOS_ENGINE__HH__