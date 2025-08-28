/**
 * @file        pokemonism/latios/internal/generator.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__

#include <pokemonism/pokemon/object.hh>
#include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/latios/internal/engine.hh>
#include <pokemonism/latios/internal/metadata.hh>

namespace pokemonism {
    namespace latios { namespace internal {

        template <class tag = internal::metadata::generator>
        class generator : public virtual pokemonism::object, public tag {
        public:     typedef decltype(tag::head)         subscription;
        public:     using                               collection = pokemonism::linked::list<generator<tag>, generator<tag>::subscription>;
        protected:  internal::engine * engine;
        public:     virtual generator<tag>::subscription * reg(generator<tag>::subscription * subscription);
        public:     virtual generator<tag>::subscription * del(generator<tag>::subscription * subscription);
        public:     virtual void clear(void);
        public:     virtual uint64 on(void);
        protected:  explicit generator(internal::engine * engine);
        protected:  generator(void) = delete;
        protected:  ~generator(void) override;
        public:     generator(const generator<tag> & o) = delete;
        public:     generator(generator<tag> && o) noexcept = delete;
        public:     generator<tag> & operator=(const generator<tag> & o) = delete;
        public:     generator<tag> & operator=(generator<tag> && o) noexcept = delete;
        public:     friend pokemonism::linked::list<generator<tag>, generator<tag>::subscription>;
        };

        template<class tag>
        generator<tag>::generator(internal::engine *engine) : tag(), engine(engine) {

        }

        template<class tag>
        generator<tag>::~generator(void) {
            generator<tag>::clear();
        }

        template<class tag>
        void generator<tag>::clear(void) {
            collection::clear(this, generator<tag>::subscription::rel);
        }

        template<class tag>
        uint64 generator<tag>::on(void) {
            return 0;
        }

        template<class tag>
        generator<tag>::subscription * generator<tag>::reg(generator<tag>::subscription * subscription) {
            collection::add(this, subscription);

            subscription->on();
            return subscription;
        }

        template<class tag>
        generator<tag>::subscription * generator<tag>::del(generator<tag>::subscription * subscription) {
            subscription->on();
            collection::del(this, subscription);
            return subscription;
        }

    } }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__