/**
 * @file        pokemon/latios/internal/descriptor/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_DESCRIPTOR_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_DESCRIPTOR_SUBSCRIPTION__HH__

#include <pokemon/latios/descriptor.hh>
#include <pokemon/latios/internal/subscription.hh>

#include <pokemon/latios/external/descriptor/subscription.hh>


namespace pokemon { namespace latios { namespace internal { namespace descriptor {

    class processor;

    class subscription : public internal::subscription, public external::descriptor::subscription {
    /** CLASS DEFINITION */
    public:     class node;
    /** STATIC TYPE DEFINITION */
    public:     typedef latios::descriptor                              target;
    public:     typedef latios::descriptor::event::listener             listener;
    public:     struct handler {
                public: typedef latios::descriptor::event::listener     set[latios::descriptor::event::max];
                };
    public:     constexpr static uint32                                 max = latios::descriptor::event::max;
    public:     struct property {
                public:     constexpr static uint32                     mask = 0x00FFFFFFU;
                };
    public:     inline uint32 maximum(void) const override { return subscription::max; }
    public:     inline latios::descriptor * objectGet(void) const override { return dynamic_cast<latios::descriptor *>(object); }
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     inline subscription(latios::command * object, uint32 properties, subscription::handlerSet * callback);
    public:     subscription(void) = delete;
    protected:  inline ~subscription(void) override;
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    public:     friend class processor;
    };

    class subscription::node : public internal::subscription::node {
    public:     inline command::subscription * subscriptionGet(void) const override { return dynamic_cast<command::subscription *>(container); }
    public:     inline explicit node(command::subscription * container) : internal::subscription::node(container) {}
    public:     node(void) = delete;
    public:     inline ~node(void) override {}
    public:     node(const node & o) = delete;
    public:     node(node && o) noexcept = delete;
    public:     node & operator=(const node & o) = delete;
    public:     node & operator=(node && o) noexcept = delete;
    };

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    // ReSharper disable once CppParameterNamesMismatch
    subscription::subscription(latios::command * object, const uint32 properties, subscription::handlerSet * callbackSet)
    : internal::subscription(object, properties, reinterpret_cast<internal::subscription::handlerSet>(callbackSet)) {
    }

    subscription::~subscription(void) {
    }

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_DESCRIPTOR_SUBSCRIPTION__HH__