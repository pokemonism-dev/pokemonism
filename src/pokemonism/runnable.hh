/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_RUNNABLE_HH__
#define   __POKEMONISM_RUNNABLE_HH__

#include <pokemonism.hh>
#include <pokemonism/sync.hh>

#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {

    class runnable {
    public:     class queue;
    public:     virtual void operator()(void) = 0;
    public:     runnable(void) {}
    public:     virtual ~runnable(void) {}
    public:     runnable(const runnable & o) = delete;
    public:     runnable(runnable && o) noexcept = delete;
    public:     runnable & operator=(const runnable & o) = delete;
    public:     runnable & operator=(runnable && o) noexcept = delete;
    };

    class runnable::queue : public sync {
    public:     class node : public runnable {
                protected:  runnable::queue * container;
                protected:  runnable::queue::node * prev;
                protected:  runnable::queue::node * next;
                public:     node(void) : container(nullptr), prev(nullptr), next(nullptr) {}
                public:     ~node(void) override {
                                if (container != nullptr) container->del(this);
                            }
                public:     node(const runnable::queue::node & o) = delete;
                public:     node(runnable::queue::node && o) noexcept = delete;
                public:     runnable::queue::node & operator=(const runnable::queue::node & o) = delete;
                public:     runnable::queue::node & operator=(runnable::queue::node && o) noexcept = delete;
                public:     friend psyduck::linked::list<runnable::queue, runnable::queue::node>;
                public:     friend runnable::queue;
                };
    public:     using                       collection = psyduck::linked::list<runnable::queue, runnable::queue::node>;
    protected:  unsigned long               size;
    protected:  runnable::queue::node *     head;
    protected:  runnable::queue::node *     tail;
    public:     inline virtual runnable::queue::node * add(runnable::queue::node * func) {
                    pokemon_training_check(func == nullptr || func->container != nullptr, return func);

                    collection::add(this, func, *this);

                    return nullptr;
                }
    public:     inline virtual runnable::queue::node * del(runnable::queue::node * func) {
                    pokemon_training_check(func == nullptr || func->container != this, return func);

                    collection::del(this, func, *this);

                    return func;
                }
    public:     inline virtual unsigned long operator()(unsigned long n = declaration::infinite) {
                    lock();
                    const unsigned long limit = size < n ? size : n;
                    for (n = 0; n < size && n < limit; n = n + 1) {
                        runnable::queue::node * func = psyduck::linked::list<runnable::queue, runnable::queue::node>::pop(this);
                        unlock();
                        if (func) {
                            (*func)();
                            allocator::del(func);
                        }
                        lock();
                    }
                    unlock();
                    return n;
                }
    public:     queue(void) : size(declaration::zero), head(nullptr), tail(nullptr) {}
    public:     ~queue(void) override { collection::clear(this, *this); }
    public:     queue(const runnable::queue & o) = delete;
    public:     queue(runnable::queue && o) noexcept = delete;
    public:     runnable::queue & operator=(const runnable::queue & o) = delete;
    public:     runnable::queue & operator=(runnable::queue && o) noexcept = delete;
    public:     friend collection;
    };

}

#endif // __POKEMONISM_RUNNABLE_HH__
