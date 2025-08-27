/**
 * @file        pokemon/latios/internal/generator.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_GENERATOR__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_GENERATOR__HH__

#include <pokemon/latios/object.hh>
#include <pokemon/latios/internal/engine.hh>
#include <pokemon/latios/internal/linked/list.hh>

namespace pokemon { namespace latios { namespace internal {

    template <typename subscription_type, typename event_type>
    class generator : public virtual object {
    /** STATIC TYPE DEFINITION */
    public:     typedef subscription_type       subscription;
    public:     typedef event_type              event;
    /** PROTECTED MEMBER VARIABLE */
    protected:  engine *                        parent;
    protected:  uint64                          size;
    protected:  subscription *                  head;
    protected:  subscription *                  tail;
    /** PUBLIC VIRTUAL METHOD */
    public:     virtual subscription * reg(subscription * o);
    public:     virtual subscription * del(subscription * o);
    public:     virtual void clear(void);
    public:     virtual uint64 on(void);
    public:     virtual event * eventGen(subscription * o, uint32 type) = 0;
    public:     virtual void dispatch(subscription * o, uint32 type) = 0;
    /** CUSTOM CLASS CONSTRUCTOR */
    public:     explicit generator(engine * parent);
    /** DEFAULT CLASS METHOD */
    public:     generator(void) = delete;
    public:     ~generator(void) override;
    public:     generator(const generator & o) = delete;
    public:     generator(generator && o) noexcept = delete;
    public:     generator & operator=(const generator & o) = delete;
    public:     generator & operator=(generator && o) noexcept = delete;
    public:     friend class linked::list;
    };

    /** PUBLIC VIRTUAL METHOD */
    template <typename subscription, typename event>
    subscription * generator<subscription, event>::reg(subscription * o) {
        if (o != nullptr && o->generatorGet() == nullptr) {
            linked::list::add(this, o);

            o->on(object::event::reg, nullptr, primitivable::object::gen(success));
        }

        return o;
    }

    template <typename subscription, typename event>
    subscription * generator<subscription, event>::del(subscription * o) {
        if (o != nullptr && o->generatorGet() == this) {
            o = linked::list::del(this, o);
            o->on(object::event::del, nullptr, primitivable::object::gen(success));
        }

        return o;
    }

    template <typename subscription, typename event>
    void generator<subscription, event>::clear(void) {
        while (head) del(head);
    }

    template <typename subscription, typename event>
    uint64 generator<subscription, event>::on(void) {
        return success;
    }

    /** CUSTOM CLASS CONSTRUCTOR */
    template <typename subscription, typename event>
    generator<subscription, event>::generator(engine * parent) : parent(parent), size(0), head(nullptr), tail(nullptr) {

    }

    /** DEFAULT CLASS METHOD */
    template <typename subscription, typename event>
    generator<subscription, event>::~generator(void) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        clear();
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_GENERATOR__HH__