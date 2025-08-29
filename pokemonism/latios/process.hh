/**
 * @file        pokemonism/latios/process.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PROCESS__HH__
#define   __POKEMONISM_LATIOS_PROCESS__HH__

#include <pokemon.hh>

#include <latios/external/event.hh>

namespace pokemonism {
    namespace latios {

        class process : public virtual pokemonism::object {
        public:     virtual int open(void) = 0;
        public:     virtual int64 read(void) = 0;
        public:     virtual int64 write(void) = 0;
        public:     virtual int close(void) = 0;
        public:     inline process(void) {}
        public:     inline ~process(void) override {}
        public:     process(const process & o) = delete;
        public:     process(process && o) noexcept = delete;
        public:     process & operator=(const process & o) = delete;
        public:     process & operator=(process && o) noexcept = delete;
        };

    }

    using process = latios::process;
}

#endif // __POKEMONISM_LATIOS_PROCESS__HH__