/**
 * @file        pokemonism/latios/internal/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__

#include <pokemonism/pokemon/object.hh>
#include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/mareep/subscription.hh>
#include <pokemonism/latios/internal/metadata.hh>

namespace pokemonism {
    namespace latios { namespace internal {

        template <class tag = internal::metadata::subscription>
        class subscription : public pokemonism::subscription, public virtual pokemonism::object, public tag {
        public:     typedef decltype(tag::container)            generator;
        public:     typedef decltype(tag::head)                 node;
        public:     virtual void on(void) {}
        protected:  subscription(void) {}
        protected:  ~subscription(void) override {}
        public:     subscription(const subscription<tag> & o) = delete;
        public:     subscription(subscription<tag> && o) noexcept = delete;
        public:     subscription<tag> & operator=(const subscription<tag> & o) = delete;
        public:     subscription<tag> & operator=(subscription<tag> && o) noexcept = delete;
        public:     friend pokemonism::linked::list<generator, subscription<tag>>;
        public:     friend pokemonism::linked::list<subscription<tag>, node>;
        };

    } }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__