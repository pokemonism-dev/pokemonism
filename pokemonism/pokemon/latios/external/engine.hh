/**
 * @file        pokemon/latios/external/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__

#include <pokemon/latios/command.hh>

namespace pokemon { namespace latios {

    namespace external {

        class engine {
        public:     virtual const char * tag(void) const = 0;
        // public:     virtual command::subscription * reg(command * command, command::on (*on)[command::event::max]) = 0;
        // public:     virtual command::subscription * reg(command::subscription * subscription, uint64 type, command::on on) = 0;
        // public:     virtual command::subscription * reg(command::subscription * subscription, command::on (*on)[command::event::max]) = 0;
        protected:  engine(void) {}
        public:     virtual ~engine(void) {}
        public:     engine(engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };

    }
} }

#endif // __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__
