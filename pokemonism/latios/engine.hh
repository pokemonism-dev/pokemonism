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

#include <pokemonism/wattrel/engine.hh>
#include <pokemonism/pokemon/generic/command.hh>

namespace pokemonism {
    namespace latios {

        namespace command {
            template <typename objectable> class subscription;
        }

        class engine : protected wattrel::engine {
        public:     static pokemon::interface::terminatable<1, latios::engine *> T;
        protected:  static latios::engine * singleton;
        public:     typedef void (*bootstrapper)(latios::engine & o);
        public:     typedef void (*cancellation)(latios::engine * o);
        public:     static void t1000(latios::engine * o);
        public:     static void on(latios::engine::bootstrapper bootstrap, wattrel::engine::bootstrapper wattrel);
        public:     static void off(latios::engine::cancellation t1000, wattrel::engine::cancellation t800);
        public:     static void off(pokemon::interface::terminator<latios::engine *> t1000, pokemon::interface::terminator<wattrel::engine *> t800);
        public:     static int run(int n);
        public:     template <class outputable, typename objectable = pokemon::generic::command<outputable>> static latios::command::subscription<objectable> * commandReg(objectable * target, uint32 properties, objectable::callback::type * callbacks, uint32 n);
        protected:  engine(void);
        protected:  ~engine(void) override;
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };

    }
}

#include <pokemonism/latios/command.hh>

namespace pokemonism {
    namespace latios {
        namespace command {

            template <class outputable, class objectable>
            latios::command::subscription<objectable> * generator::reg(objectable * target, uint32 properties, typename objectable::callback::type * callbacks, uint32 n) {
                latios::command::subscription<objectable> * subscription = new latios::command::subscription<objectable>(target, properties, callbacks, n);

                subscription->on(wattrel::command::event::type::gen);

                printf("call\n");

                if (add(subscription) != declaration::success) return allocator::del(subscription);

                wattrel::command::event * event = new wattrel::command::event(wattrel::command::event::type::execute, new wattrel::command::node(subscription));

                engine->push(event);

                return subscription;
            }

        }

        template <class outputable, typename objectable>
        latios::command::subscription<objectable> * engine::commandReg(objectable * target, uint32 properties, typename objectable::callback::type * callbacks, uint32 n) {
            if (singleton == nullptr) throw pokemon::exception();

            latios::command::generator * o = dynamic_cast<latios::command::generator *>(singleton->generator.command);

            return o->reg<outputable, objectable>(target, properties, callbacks, n);
        }
    }
}

#endif // __POKEMONISM_LATIOS_ENGINE_HH__