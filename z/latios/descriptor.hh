/**
 * @file        pokemonism/latios/descriptor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_LATIOS_DESCRIPTOR__HH__
#define   __POKEMONISM_LATIOS_DESCRIPTOR__HH__

#include <pokemon.hh>

#include <latios/external/event.hh>

namespace pokemonism {
    namespace latios {

        class descriptor : public virtual pokemonism::object {
        public:     virtual int open(void) = 0;
        public:     virtual int64 read(void) = 0;
        public:     virtual int64 write(void) = 0;
        public:     virtual int close(void) = 0;
        public:     inline descriptor(void) {}
        public:     inline ~descriptor(void) override {}
        public:     descriptor(const descriptor & o) = delete;
        public:     descriptor(descriptor && o) noexcept = delete;
        public:     descriptor & operator=(const descriptor & o) = delete;
        public:     descriptor & operator=(descriptor && o) noexcept = delete;
        };

    }

    using descriptor = latios::descriptor;
}

#endif // __POKEMONISM_LATIOS_DESCRIPTOR__HH__