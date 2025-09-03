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

        template <class evolvable>
        class engine {
        public:     using                                                                                                                   evolution = evolvable;
        public:     typedef evolution::terminator                                                                                           terminator;
        public:     struct command {
                    public:     using                                                                                                       subscription = evolution::command::subscription;
                    public:     typedef evolution::command::object                                                                          object;
                    public:     struct handler {
                                public:     typedef evolution::command::object::event::handler::set                                         set;
                                };
                    public:     struct event {
                                public:     struct subscription {
                                            public:     struct handler {
                                                        public:     typedef evolution::command::subscription::event::handler::set   set;
                                                        };
                                            };
                                };
                    };
        public:     static kirlia::engine<evolution>::command::subscription * reg(kirlia::engine<evolution>::command::object * target, uint32 properties, const kirlia::engine<evolution>::command::handler::set & eventSet);
        public:     static kirlia::engine<evolution>::command::subscription * reg(kirlia::engine<evolution>::command::object * target, uint32 properties, const kirlia::engine<evolution>::command::handler::set & eventSet, const kirlia::engine<evolution>::command::event::subscription::handler::set & subscriptionSet);
        public:     static kirlia::engine<evolution>::command::subscription * reg(kirlia::engine<evolution>::command::object * target, int32 repeat, uint32 properties, const kirlia::engine<evolution>::command::handler::set & eventSet);
        public:     static kirlia::engine<evolution>::command::subscription * reg(kirlia::engine<evolution>::command::object * target, int32 repeat, uint32 properties, const kirlia::engine<evolution>::command::handler::set & eventSet, const kirlia::engine<evolution>::command::event::subscription::handler::set & subscriptionSet);
        public:     static int on(void);
        public:     static void off(terminator f);
        public:     static int run(void);
        protected:  engine(void) {}
        protected:  virtual ~engine(void) {}
        public:     engine(const kirlia::engine<evolvable> & o) = delete;
        public:     engine(kirlia::engine<evolvable> && o) noexcept = delete;
        public:     kirlia::engine<evolvable> & operator=(const kirlia::engine<evolvable> & o) = delete;
        public:     kirlia::engine<evolvable> & operator=(kirlia::engine<evolvable> && o) noexcept = delete;
        };

        template <class evolution>
        kirlia::engine<evolution>::command::subscription * engine<evolution>::reg(typename kirlia::engine<evolution>::command::object * target, uint32 properties, const typename kirlia::engine<evolution>::command::handler::set & eventSet) {
            return evolution::reg(target, properties, eventSet);
        }

        template <class evolution>
        kirlia::engine<evolution>::command::subscription * engine<evolution>::reg(typename kirlia::engine<evolution>::command::object * target, uint32 properties, const typename kirlia::engine<evolution>::command::handler::set & eventSet, const typename kirlia::engine<evolution>::command::event::subscription::handler::set & subscriptionSet) {
            return evolution::reg(target, properties, eventSet, subscriptionSet);
        }

        template <class evolution>
        kirlia::engine<evolution>::command::subscription * engine<evolution>::reg(typename kirlia::engine<evolution>::command::object * target, int32 repeat, uint32 properties, const typename kirlia::engine<evolution>::command::handler::set & eventSet) {
            return evolution::reg(target, repeat, properties, eventSet);
        }

        template <class evolution>
        kirlia::engine<evolution>::command::subscription * engine<evolution>::reg(typename kirlia::engine<evolution>::command::object * target, int32 repeat, uint32 properties, const typename kirlia::engine<evolution>::command::handler::set & eventSet, const typename kirlia::engine<evolution>::command::event::subscription::handler::set & subscriptionSet) {
            return evolution::reg(target, repeat, properties, eventSet, subscriptionSet);
        }
        template <class evolution>
        int engine<evolution>::on(void) {
            return evolution::on();
        }

        template <class evolution>
        void engine<evolution>::off(terminator f) {
            return evolution::off(f);
        }

        template <class evolution>
        int engine<evolution>::run(void) {
            return evolution::run();
        }

    }
}

#endif // __POKEMONISM_KIRLIA_ENGINE_HH__