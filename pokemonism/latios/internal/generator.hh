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

#include <pokemonism/latios/general/generator.hh>
#include <pokemonism/latios/internal/event.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            template <class objectable>
            class generator : public general::generator {
            public:     typedef internal::event<objectable, generator<objectable>>  event;
            public:     typedef event::subscription                                 subscription;
            public:     struct                                                      node;
            public:     using                                                       collector = linked::list<generator<objectable>, subscription>;
            public:     typedef struct node                                         node;
            public:     struct node {
                        public:     generator<objectable> *                         container;
                        protected:  subscription *                                  prev;
                        protected:  subscription *                                  next;
                        public:     inline node(void);
                        public:     inline ~node(void);
                        };
            protected:  uint64 size;
            protected:  subscription * head;
            protected:  subscription * tail;
            public:     virtual event * eventGen(subscription * node, uint32 type);
            public:     virtual event * dispatch(subscription * node, uint32 type);
            public:     virtual int add(subscription * node);
            public:     virtual int del(subscription * node);
            public:     void clear(void) override;
            public:     explicit generator(general::engine * engine);
            public:     generator(void) = delete;
            public:     ~generator(void) override;
            public:     generator(const generator<objectable> & o) = delete;
            public:     generator(generator<objectable> && o) noexcept = delete;
            public:     generator<objectable> & operator=(const generator<objectable> & o) = delete;
            public:     generator<objectable> & operator=(generator<objectable> && o) noexcept = delete;
            };

            template <class objectable>
            generator<objectable>::generator(general::engine * engine) : general::generator(engine), size(declaration::zero), head(nullptr), tail(nullptr) {

            }

            template <class objectable>
            generator<objectable>::~generator(void) {
                generator<objectable>::clear();
            }

            template <class objectable>
            generator<objectable>::event * generator<objectable>::eventGen(subscription * node, uint32 type) {
                if (node == nullptr) throw pokemonism::exception();

                return subscription::eventGen(node, type);
            }

            template <class objectable>
            generator<objectable>::event * generator<objectable>::dispatch(subscription * node, uint32 type) {
                if (const int ret = generator<objectable>::event::processor::on(node, type, nullptr); ret > success) generator<objectable>::eventGen(node, type);

                return nullptr;
            }

            template <class objectable>
            int generator<objectable>::add(subscription * node) {
                if (node == nullptr || node->container != nullptr) throw pokemonism::exception();

                collector::add(this, node);

                node->on(generator<objectable>::event::add, nullptr, primitivable::object::gen(success), nullptr);

                return declaration::success;
            }

            template <class objectable>
            int generator<objectable>::del(subscription * node) {
                if (node == nullptr || node->container != this) throw pokemonism::exception();

                collector::del(this, node);

                node->on(generator<objectable>::event::del, nullptr, primitivable::object::gen(success), nullptr);

                return declaration::success;
            }

            template <class objectable>
            void generator<objectable>::clear(void) {
                while (head) collector::del(this, head);
            }

            template <class objectable>
            generator<objectable>::node::node(void) : container(nullptr), prev(nullptr), next(nullptr) {

            }

            template <class objectable>
            generator<objectable>::node::~node(void) {
                if (container != nullptr) throw pokemonism::exception();
            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_GENERATOR__HH__
