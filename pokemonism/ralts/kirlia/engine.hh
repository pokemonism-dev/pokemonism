/**
 * @file            pokemonism/ralts/kirlia/engine.hh
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_KIRLIA_ENGINE_HH__
#define   __POKEMONISM_KIRLIA_ENGINE_HH__

#include <pokemonism/pokemon/command.hh>
#include <pokemonism/ralts/kirlia/command.hh>
#include <pokemonism/ralts/kirlia/subscription.hh>

namespace pokemonism {
    namespace kirlia {

        class engine {
        public:     typedef void (*terminator)(void);
        public:     static kirlia::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet);
        public:     static kirlia::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet);
        public:     static kirlia::command::subscription * reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet);
        public:     static kirlia::command::subscription * reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet);
        public:     static int on(void);
        public:     static void off(kirlia::engine::terminator terminator);
        public:     static int run(void);
        protected:  engine(void);
        protected:  virtual ~engine(void);
        public:     engine(const kirlia::engine & o) = delete;
        public:     engine(kirlia::engine && o) noexcept = delete;
        public:     kirlia::engine & operator=(const kirlia::engine & o) = delete;
        public:     kirlia::engine & operator=(kirlia::engine && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_KIRLIA_ENGINE_HH__