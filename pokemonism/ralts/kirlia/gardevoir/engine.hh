/**
 * @file            pokemonism/ralts/kirlia/gardevoir/engine.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_ENGINE_HH__
#define   __POKEMONISM_GARDEVOIR_ENGINE_HH__

#include <pokemonism/pokemon/sync.hh>
#include <pokemonism/pokemon/command.hh>
#include <pokemonism/ralts/kirlia/gardevoir/queue.hh>
#include <pokemonism/ralts/kirlia/gardevoir/command.hh>

namespace pokemonism {
    namespace gardevoir {

        class subscription;

        class engine {
        public:     typedef void (*terminator)(void);
        public:     struct generator {
                    public:     struct set {
                                public:     gardevoir::command::generator * command;
                                public:     set(void) : command(nullptr) {}
                                };
                    };
        protected:  static pokemon::sync sync;
        protected:  static gardevoir::queue * queue;
        protected:  static gardevoir::engine::terminator cancel;
        protected:  static gardevoir::engine::generator::set generator;
        protected:  static gardevoir::engine * singleton;
        public:     static gardevoir::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet);
        public:     static gardevoir::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet);
        public:     static gardevoir::command::subscription * reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet);
        public:     static gardevoir::command::subscription * reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet);
        public:     static gardevoir::event * dispatch(gardevoir::event * event) { return queue->add(event); }
        public:     static int on(void);
        public:     static void off(terminator f) { cancel = f; }
        public:     static int run(void);
        public:     engine(void) {}
        public:     virtual ~engine(void) {}
        public:     engine(const gardevoir::engine & o) = delete;
        public:     engine(gardevoir::engine && o) noexcept = delete;
        public:     gardevoir::engine & operator=(const gardevoir::engine & o) = delete;
        public:     gardevoir::engine & operator=(gardevoir::engine && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_GARDEVOIR_ENGINE_HH__