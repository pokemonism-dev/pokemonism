/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_ENGINE_HH__
#define   __POKEMONISM_WATTREL_ENGINE_HH__

#include <pokemonism.hh>

#include <pokemonism/pokemon/allocator.hh>

#include <pokemonism/wattrel/command.hh>
#include <pokemonism/wattrel/queue.hh>
#include <pokemonism/pokemon/interface/terminatable.hh>

namespace pokemonism {

    namespace wattrel {

        inline void t800(wattrel::engine * o) {}

        class engine {
        public:     typedef void (*cancellation)(wattrel::engine * o);
        public:     typedef void (*bootstrapper)(wattrel::engine & o);
        public:     static  pokemon::interface::terminatable<1, wattrel::engine *> T;
        public:     struct generator {
                    public:     struct set {
                                public:     command::generator * command;
                                public:     inline set(void) : command(nullptr) {}
                                public:     inline ~set(void);
                                };
                    };
        public:     static pokemon::event::subscription * del(pokemon::event::subscription * subscription);
        public:     static pokemon::event::subscription * rel(pokemon::event::subscription * subscription);
        public:     virtual int run(void);
        public:     virtual void on(wattrel::engine::bootstrapper bootstrap);
        public:     virtual void off(wattrel::engine::cancellation executor);
        public:     inline virtual void push(wattrel::event * event) { queue->add(event); }
        public:     virtual pokemon::event::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n);
        protected:  wattrel::queue * queue;
        protected:  pokemon::interface::terminator<wattrel::engine *> terminator;
        protected:  wattrel::engine::generator::set generator;
        public:     engine(void);
        public:     virtual ~engine(void);
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };

        inline engine::generator::set::~set(void) {
            command = pokemon::allocator::del(command);
        }

        // inline wattrel::engine::terminator * operator-(wattrel::engine::terminator * func, long n) {
        //     switch (n) {
        //         case 800:   return wattrel::engine::t800;
        //         default:    return wattrel::engine::t800;
        //     }
        // }
    }
}

#endif // __POKEMONISM_WATTREL_ENGINE_HH__