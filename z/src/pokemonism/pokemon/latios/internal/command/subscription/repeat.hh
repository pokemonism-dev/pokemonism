/**
 * @file        pokemon/latios/internal/command/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTIONS_REPEAT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTIONS_REPEAT__HH__

#include <pokemon/latios/internal/command/subscription.hh>

namespace pokemon { namespace latios { namespace internal { namespace command { namespace subscriptions {

    class repeat : public command::subscription {
    /** CLASS DEFINITION */
    public:     class node;
    /** STATIC TYPE DEFINITION */
    public:     typedef latios::command                     target;
    public:     typedef latios::command::event::listener    listener;
    public:     typedef latios::command::event::listener    handlerSet[latios::command::event::max];
    public:     constexpr static uint32                     max = latios::command::event::max;
    public:     struct property {
                public:     constexpr static uint32         mask = 0x00FFFFFFU;
                };
    protected:  int total;
    protected:  int count;
    public:     int complete(void) override { return total <= count; }
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     inline repeat(latios::command * object, uint32 properties, int total, command::subscription::handlerSet * callback);
    public:     repeat(void) = delete;
    protected:  inline ~repeat(void) override;
    public:     repeat(const repeat & o) = delete;
    public:     repeat(repeat && o) noexcept = delete;
    public:     repeat & operator=(const repeat & o) = delete;
    public:     repeat & operator=(repeat && o) noexcept = delete;
    public:     friend class processor;
    };

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    // ReSharper disable once CppParameterNamesMismatch
    repeat::repeat(latios::command * object, const uint32 properties, const int total, command::subscription::handlerSet * callbackSet)
    : command::subscription(object, properties, callbackSet), total(total), count(0) {
    }

    repeat::~repeat(void) {
    }



} } } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTIONS_REPEAT__HH__
