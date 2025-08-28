/**
 * @file        pokemon/latios/internal/command/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__

#include <pokemonism.hh>

#include <pokemon/latios/event.hh>

#include <pokemon/latios/internal/event.hh>
#include <pokemon/latios/internal/command/subscription.hh>
#include <pokemon/latios/external/command/event.hh>

namespace pokemon { namespace latios { namespace internal { namespace command {

    class generator;

    class event : public internal::event, public external::command::event {
    public:     inline command::subscription * subscriptionGet(void) const { return dynamic_cast<command::subscription *>(node->subscriptionGet()); }
    /** OVERRIDE INTERNAL::EVENT */
    public:     int on(pokemon::exception * e) override;
    /** CUSTOM CONSTRUCTOR */
    public:     inline explicit event(uint32 type, subscription::node * node);
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     event(void) = delete;
    public:     inline ~event(void) override;
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    public:     friend class generator;
    };

} } } }

namespace pokemon { namespace latios { namespace internal { namespace command {

    /** CUSTOM CONSTRUCTOR */
    event::event(const uint32 type, subscription::node * node) : latios::event(type), internal::event(node) {
    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    event::~event(void) {
    }

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__