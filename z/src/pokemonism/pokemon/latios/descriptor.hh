/**
 * @file        pokemon/latios/descriptor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_DESCRIPTOR__HH__
#define   __POKEMONISM_POKEMON_LATIOS_DESCRIPTOR__HH__

#include <pokemon/primitivable.hh>

#include <pokemon/latios/object.hh>
#include <pokemon/latios/subscription.hh>

#include <pokemon/sprigatito/packet.hh>
#include <pokemon/sprigatito/string.hh>

namespace pokemon { namespace latios {

    using packet = pokemon::sprigatito::packet;
    using string = pokemon::sprigatito::string;

    namespace external {
        class engine;
        namespace descriptor {
            class event;
        }
    }

    class descriptor : public virtual object {
    public:     struct property {
                public:     constexpr static uint32 socket      = (0x00000001U <<  0U);
                public:     constexpr static uint32 console     = (0x00000001U <<  1U);
                public:     constexpr static uint32 file        = (0x00000001U <<  2U);

                public:     constexpr static uint32 server      = (0x00000100U <<  0U);
                public:     constexpr static uint32 client      = (0x00000100U <<  1U);
                public:     constexpr static uint32 session     = (0x00000100U <<  2U);

                public:     constexpr static uint32 nonblock    = (0x00010000U <<  0U);
                };
    public:     class event {
                public:     struct subscription {
                            public:     struct property {
                                        public:     constexpr static uint32     release_on_del = latios::subscription::property::release_on_del;
                                        public:     constexpr static uint32     release_object_on_rel = latios::subscription::property::release_object_on_rel;
                                        };
                            };
                public:     typedef int (*listener)(descriptor *, uint32, external::descriptor::event *, primitivable::object *, pokemon::exception * e);
                public:     constexpr static int        gen   = object::event::gen;
                public:     constexpr static int        rem   = object::event::rem;
                public:     constexpr static int        reg   = object::event::reg;
                public:     constexpr static int        del   = object::event::del;
                public:     constexpr static int        open  = object::event::max + 0;
                public:     constexpr static int        read  = object::event::max + 1;
                public:     constexpr static int        write = object::event::max + 2;
                public:     constexpr static int        close = object::event::max + 3;
                public:     constexpr static int        max   = object::event::max + 4;
                };
    public:     virtual uint32 status(void) const = 0;
    public:     virtual uint32 properties(void) const = 0;
    public:     virtual exception * exception(void) const = 0;
    public:     virtual uint32 type(void) const = 0;
    public:     virtual int open(void) = 0;
    public:     virtual int close(void) = 0;
    public:     virtual packet & read(packet & o);
    public:     virtual string & write(string & o);
    public:     inline descriptor(void) {}
    public:     inline ~descriptor(void) override {}
    public:     descriptor(const descriptor & o) = delete;
    public:     descriptor(descriptor && o) noexcept = delete;
    public:     descriptor & operator=(const descriptor & o) = delete;
    public:     descriptor & operator=(descriptor && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_DESCRIPTOR__HH__