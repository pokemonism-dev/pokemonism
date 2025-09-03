/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_LATIOS_ENGINE_HH__
#define   __POKEMONISM_LATIOS_ENGINE_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace latios {

        class engine {
        public:     static int on(void);
        public:     static void off(void (*terminator)(void));
        public:     static int run(void);
        // public:     static gardevoir::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet);
        // public:     static gardevoir::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet);
        // public:     static gardevoir::command::subscription * reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet);
        // public:     static gardevoir::command::subscription * reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet);
        public:     engine(void);
        public:     virtual ~engine(void);
        public:     engine(const latios::engine & o) = delete;
        public:     engine(latios::engine && o) noexcept = delete;
        public:     latios::engine & operator=(const latios::engine & o) = delete;
        public:     latios::engine & operator=(latios::engine && o) noexcept = delete;
        };

    }
}


#endif // __POKEMONISM_LATIOS_ENGINE_HH__