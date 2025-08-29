/**
 * @file        pokemonism/latios/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_LATIOS_COMMAND__HH__
#define   __POKEMONISM_LATIOS_COMMAND__HH__

#include <pokemon.hh>

#include <latios/external/event.hh>

namespace pokemonism {
    namespace latios {

        class command : public virtual pokemonism::object {
        public:     class event : public virtual external::event<command> {
                    public:     constexpr static uint32     gen     = external::event<command>::gen;
                    public:     constexpr static uint32     rel     = external::event<command>::rel;
                    public:     constexpr static uint32     add     = external::event<command>::add;
                    public:     constexpr static uint32     del     = external::event<command>::del;
                    public:     constexpr static uint32     execute = external::event<command>::max;
                    public:     constexpr static uint32     max     = external::event<command>::max + 1;
                    };
        public:     virtual primitivable::object * operator()(void) = 0;
        public:     inline command(void) {}
        public:     inline ~command(void) override {}
        public:     command(const command & o) = delete;
        public:     command(command && o) noexcept = delete;
        public:     command & operator=(const command & o) = delete;
        public:     command & operator=(command && o) noexcept = delete;
        };

    }

    using command = latios::command;
}

#endif // __POKEMONISM_LATIOS_COMMAND__HH__