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

    class subscription;
    class engine;

    class generator : public virtual object {
    /** PROTECTED MEMBER VARIABLE */
    protected:  engine *                    parent;
    protected:  uint64                      size;
    protected:  internal::subscription *    head;
    protected:  internal::subscription *    tail;
    /** PUBLIC VIRTUAL METHOD */
    public:     inline internal::subscription * reg(internal::subscription * o);
    public:     inline internal::subscription * del(internal::subscription * o);
    public:     inline virtual void clear(void);
    public:     inline virtual uint64 on(void);
    /** CUSTOM CLASS CONSTRUCTOR */
    protected:  inline explicit generator(engine * parent);
    /** DEFAULT CLASS METHOD */
    public:     generator(void) = delete;
    public:     inline ~generator(void) override;
    public:     generator(const generator & o) = delete;
    public:     generator(generator && o) noexcept = delete;
    public:     generator & operator=(const generator & o) = delete;
    public:     generator & operator=(generator && o) noexcept = delete;
    public:     friend class linked::list<generator, internal::subscription>;
    };

} } }

#include <pokemon/latios/internal/subscription.hh>

namespace pokemon { namespace latios { namespace internal {
    /** PUBLIC VIRTUAL METHOD */
    internal::subscription * generator::reg(internal::subscription * o) {
        if (o != nullptr && o->generatorGet() == nullptr) {
            linked::list<generator, internal::subscription>::add(this, o);
            o->on(object::event::reg, nullptr, primitivable::object::gen(success), nullptr);
        }
        return o;
    }

    internal::subscription * generator::del(internal::subscription * o) {
        if (o != nullptr && o->generatorGet() == this) {
            linked::list<generator, internal::subscription>::del(this, o);
            o->on(object::event::del, nullptr, primitivable::object::gen(success), nullptr);
        }
        return o;
    }

    void generator::clear(void) {
        while (head != nullptr) linked::list<generator, internal::subscription>::del(this, head);
    }

    uint64 generator::on(void) {
        return 0;
    }

    /** CUSTOM CLASS CONSTRUCTOR */
    generator::generator(engine * parent) : parent(parent), size(0), head(nullptr), tail(nullptr) {
    }

    /** DEFAULT CLASS METHOD */
    generator::~generator(void) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        clear();
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_GENERATOR__HH__