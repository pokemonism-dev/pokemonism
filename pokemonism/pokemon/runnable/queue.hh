/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_POKEMON_RUNNABLE_QUEUE_HH__
#define   __POKEMONISM_POKEMON_RUNNABLE_QUEUE_HH__

#include <pokemonism/pokemon/interface/callable.hh>
#include <pokemonism/pokemon/interface/runnable.hh>

#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {
    namespace pokemon {
        namespace runnable {
            class queue : public pokemon::interface::callable<uint64> {
            public:     class func;
            public:     using collection = psyduck::linked::list<queue, func>;
            public:     class func : public pokemon::interface::runnable {
                        private:    queue * container;
                        private:    func * prev;
                        private:    func * next;
                        public:     void operator()(void) override = 0;
                        public:     func(void) : container(nullptr), prev(nullptr), next(nullptr) {}
                        public:     ~func(void) override {
                                        if (container != nullptr) collection::del(container, this);
                                    }
                        public:     func(const func & o) = delete;
                        public:     func(func && o) noexcept = delete;
                        public:     func & operator=(const func & o) = delete;
                        public:     func & operator=(func && o) noexcept = delete;
                        public:     friend collection;
                        public:     friend queue;
                        };
            public:     static func * rel(func * o) {
                            if (o != nullptr) {
                                (*o)();
                            }
                            return o;
                        }
            protected:  uint64 size;
            protected:  func * head;
            protected:  func * tail;
            public:     inline virtual void add(queue::func * o) { if (o != nullptr) collection::add(this, o);  }
            public:     inline virtual void del(queue::func * o) { if (o != nullptr && o->container == this) collection::del(this, o); }
            public:     inline virtual void trash(void) { collection::clear(this); }
            public:     inline virtual uint64 on(uint64 n = declaration::infinite) {
                            const uint64 limit = n;

                            for (n = 0; n < limit && n < size; n = n + 1) allocator::del(queue::rel(collection::pop(this)));

                            return n;
                        }
            public:     uint64 operator()(void) override {
                            const uint64 n = size;
                            collection::clear(this, queue::rel);
                            return n;
                        }
            public:     queue(void) : size(declaration::zero), head(nullptr), tail(nullptr) {}
            public:     ~queue(void) override { collection::clear(this, queue::rel); }
            public:     queue(const queue & o) = delete;
            public:     queue(queue && o) noexcept = delete;
            public:     queue & operator=(const queue & o) = delete;
            public:     queue & operator=(queue && o) noexcept = delete;
            public:     friend collection;
            };
        }
    }
}

#endif // __POKEMONISM_POKEMON_RUNNABLE_QUEUE_HH__