/**
 * @file        pokemon/latios/internal.temp/command/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__

#include <pokemon/latios/internal.temp/event.hh>
#include <pokemon/latios/internal.temp/command/subscription.hh>

namespace pokemon { namespace latios { namespace internal { namespace command {

    template <typename subscription_node_type = subscription::node>
    class event : public internal::event {
    /** PUBLIC TYPE DEFINITION */
    public:     typedef subscription_node_type      node;
    /** PROTECTED MEMBER VARIABLE */
    protected:  node *                              link;
    /** OVERRIDE INTERNAL::EVENT METHOD */
    public:     bool cancel(void) override;
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     inline event(uint32 type, node * link);
    protected:  inline ~event(void) override;
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

    template <typename node>
    event<node>::event(const uint32 type, node * link) : internal::event(type), link(link) {

    }

    template <typename node>
    event<node>::~event(void) {
        if (link != nullptr) link = node::unlink(link);
    }

    template <typename node>
    bool event<node>::cancel(void) {
        if (container != nullptr) {
            linked::list::del(container, this);

            if (link != nullptr || (link->event = nullptr) == nullptr) link = node::unlink(link);
            return true;
        }

        if (link != nullptr || (link->event = nullptr) == nullptr) link = node::unlink(link);
        return false;
    }

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__