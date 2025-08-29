/**
 * @file        pokemonism/latios/internal/generator.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__

// #include <pokemonism/latios/internal/engine.hh>
// #include <pokemonism/latios/internal/processor.hh>
// #include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/latios/general/generator.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            template <class objectable>
            class generator : public general::generator {
            public:     virtual int add(void);
            public:     virtual int del(void);

            // public:     virtual void clear(void) = 0;
            public:     void clear(void) override;
            public:     generator(general::engine * engine);
            public:     generator(void) = delete;
            public:     ~generator(void) override;
            public:     generator(const generator<objectable> & o) = delete;
            public:     generator(generator<objectable> && o) noexcept = delete;
            public:     generator<objectable> & operator=(const generator<objectable> & o) = delete;
            public:     generator<objectable> & operator=(generator<objectable> && o) noexcept = delete;
            };

            // class generator : public virtual pokemonism::object {
            // public:     struct                                      node;
            // public:     typedef struct node                         node;
            // public:     struct node {
            //             public:     internal::generator *           container;
            //             protected:  internal::generator::node *     prev;
            //             protected:  internal::generator::node *     next;
            //             public:     inline node(void);
            //             public:     inline ~node(void);
            //             };
            // public:     using                                       processor = internal::processor;
            // public:     using                                       collection = pokemonism::linked::list<generator, generator::node>;
            // protected:  internal::engine *                          engine;
            // protected:  uint64                                      size;
            // protected:  internal::generator::node *                 head;
            // protected:  internal::generator::node *                 tail;
            // protected:  inline virtual int add(generator::node * node);
            // protected:  inline virtual int del(generator::node * node);
            // public:     inline virtual event * eventGen(subscription * node, uint32 type);
            // public:     inline virtual uint64 on(void);
            // public:     inline virtual void clear(void);
            // public:     inline explicit generator(internal::engine * engine);
            // public:     generator(void) = delete;
            // public:     inline ~generator(void) override;
            // public:     generator(const generator & o) = delete;
            // public:     generator(generator && o) noexcept = delete;
            // public:     generator & operator=(const generator & o) = delete;
            // public:     generator & operator=(generator && o) noexcept = delete;
            // public:     friend pokemonism::linked::list<generator, generator::node>;
            // };
            //
            // generator::generator(internal::engine * engine) : engine(engine), size(0), head(nullptr), tail(nullptr) {
            //
            // }
            //
            // generator::~generator(void) {
            //     engine = nullptr;
            //     generator::clear();
            // }
            //
            // void generator::clear(void) {
            //
            // }
            //
            // generator::node::node(void) : container(nullptr), prev(nullptr), next(nullptr) {
            //
            // }
            //
            // generator::node::~node(void) {
            //     if (container != nullptr) throw pokemonism::exception());
            // }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__
