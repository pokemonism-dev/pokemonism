/**
 * @file        pokemon/latios/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__
#define   __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__

#include <pokemon/primitivable.hh>

#include <pokemon/latios/object.hh>

#include <pokemon/latios/external/command/event.hh>

namespace pokemon { namespace latios {

    class command : public object {
    public:     class event {
                public:     typedef int (*listener)(command *, uint32, external::command::event *, primitivable::object *);
                public:     constexpr static int        gen = object::event::gen;
                public:     constexpr static int        rem = object::event::rem;
                public:     constexpr static int        reg = object::event::reg;
                public:     constexpr static int        del = object::event::del;
                public:     constexpr static int        exe = object::event::max + 0;
                public:     constexpr static int        max = object::event::max + 1;
                public:     typedef listener            handlerSet[max];
                public:     static const handlerSet     printableCallbackSet;
                public:     static int engineOff(command * o, uint32 type, external::command::event * event, primitivable::object * result);
                public:     static int printableOn(command * o, uint32 type, external::command::event * event, primitivable::object * result);
                };
    public:     virtual primitivable::object * operator()(void) = 0;
    public:     inline command(void) {}
    public:     inline ~command(void) override {}
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__