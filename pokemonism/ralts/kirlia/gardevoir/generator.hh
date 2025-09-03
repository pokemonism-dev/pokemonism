/**
 * @file            pokemonism/ralts/kirlia/gardevoir/generator.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GENERATOR_HH__
#define   __POKEMONISM_GENERATOR_HH__

#include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/pokemon/object.hh>
#include <pokemonism/pokemon/runnable/queue.hh>

namespace pokemonism {
    namespace gardevoir {
        class engine;
        class subscription;

        class generator : public pokemon::object {
        public:     typedef psyduck::linked::list<gardevoir::generator, gardevoir::subscription> collection;
        protected:  gardevoir::engine *         engine;
        protected:  pokemon::runnable::queue    queue;
        protected:  uint64                      size;
        protected:  gardevoir::subscription *   head;
        protected:  gardevoir::subscription *   tail;
        public:     inline virtual pokemon::runnable::queue::func * add(pokemon::runnable::queue::func * f) { return queue.add(f); }
        public:     inline virtual pokemon::runnable::queue::func * del(pokemon::runnable::queue::func * f) { return queue.del(f); }
        public:     virtual gardevoir::subscription * reg(gardevoir::subscription * o);
        public:     virtual gardevoir::subscription * del(gardevoir::subscription * o);
        public:     virtual uint64 on(void) = 0;
        public:     inline void clear(void) {
                        while (head) del(head);

                        queue.clear();
                    }
        protected:  inline explicit generator(gardevoir::engine * engine) : engine(engine), size(declaration::zero), head(nullptr), tail(nullptr) {
                        pokemon_develop_exit_check(engine == nullptr, (void)(0));
                    }
        public:     generator(void) = delete;
        public:     inline ~generator(void) override {
                        clear();
                        engine = nullptr;
                    }
        public:     generator(const gardevoir::generator & o) = delete;
        public:     generator(gardevoir::generator && o) noexcept = delete;
        public:     gardevoir::generator & operator=(const gardevoir::generator & o) = delete;
        public:     gardevoir::generator & operator=(gardevoir::generator && o) noexcept = delete;
        public:     friend collection;
        public:     friend gardevoir::subscription;

        };
    }
}

#endif // __POKEMONISM_GENERATOR_HH__