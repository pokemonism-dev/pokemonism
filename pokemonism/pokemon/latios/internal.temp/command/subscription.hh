/**
 * @file        pokemon/latios/internal.temp/command/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__

#include <pokemon/latios.hh>

#include <pokemon/latios/internal.temp/subscription.hh>

namespace pokemon { namespace latios { namespace internal { namespace command {

    template <typename subscription> class generator;

    class subscription : public internal::subscription<latios::command>, public latios::command::subscription {
    /** PUBLIC TYPE DEFINITION */
    public:     typedef latios::command     object;
    public:     typedef internal::subscription<latios::command>::handler handler;
    /** INTERNAL CLASS DEFINITION */
    public:     class node;

    /** STATIC DESCRIPTION */
    public:     constexpr static int        max = internal::subscription<latios::command>::max;
    /** VIRTUAL METHOD */
    // public:     virtual void clear(void);
    // public:     virtual subscription * rem(void);
    // public:     virtual void on(uint32 type, primitivable::object * result);
    /** CUSTOM CONSTRUCTOR */
    public:     inline subscription(object * origin, handler * on, uint32 properties);
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     subscription(void) = delete;
    public:     inline ~subscription(void) override;
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };


    class subscription::node : public internal::subscription<latios::command>::node<command::event> {
    protected:  subscription *  container;
    protected:  node *          prev;
    protected:  node *          next;
    public:     node(void) : container(nullptr), prev(nullptr), next(nullptr) {}
    public:     ~node(void) override {
                }
    public:     node(const node & o) = delete;
    public:     node(node && o) noexcept = delete;
    public:     node & operator=(const node & o) = delete;
    public:     node & operator=(node && o) noexcept = delete;
    };

    /** CUSTOM CONSTRUCTOR */
    subscription::subscription(object * origin, handler * on, uint32 properties) : internal::subscription<latios::command>(origin, on, properties) {

    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    subscription::~subscription(void) {

    }

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__