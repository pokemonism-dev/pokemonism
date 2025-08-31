/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_LATIOS_COMMAND_HH__
#define   __POKEMONISM_LATIOS_COMMAND_HH__

#include <pokemonism.hh>

#include <pokemonism/wattrel/command.hh>
#include <pokemonism/pokemon/generic/command.hh>
#include <pokemonism/latios/subscription.hh>

namespace pokemonism {
    namespace latios {

        namespace command {
            struct tag {};


            template <class messageable = wattrel::command::envelope::message>
            class envelope : public wattrel::command::envelope, public pokemon::generic::command<messageable>::envelope {
            public:     typedef messageable             message;
            public:     inline message * pop(void) override { return dynamic_cast<messageable *>(output); }
            public:     inline envelope(void) {}
            public:     inline explicit envelope(pokemon::exception * e) : wattrel::command::envelope(e) {}
            public:     inline ~envelope(void) override {}
            public:     envelope(const envelope & o) = delete;
            public:     envelope(envelope && o) noexcept = delete;
            public:     envelope & operator=(const envelope & o) = delete;
            public:     envelope & operator=(envelope && o) noexcept = delete;
            };
        }

        template <class objectable>
        class subscription<objectable, typename objectable::output, pokemon::command::tag> : public virtual wattrel::subscription {
        public:     constexpr static const char * name = "command";   // ### 20250901 | REMOVE THIS FOR DEBUG
        public:     explicit subscription(uint32 properties) : wattrel::subscription(properties) {}
        public:     subscription(void) = delete;
        public:     ~subscription(void) override {}
        public:     subscription(const subscription & o) = delete;
        public:     subscription(subscription && o) noexcept = delete;
        public:     subscription & operator=(const subscription & o) = delete;
        public:     subscription & operator=(subscription && o) noexcept = delete;
        };

        namespace command {

            template <typename objectable> class subscription;

            // // typedef pokemon::command::output    output;
            // // typedef pokemon::command::callback  callback;
            //


            // template <class ...>
            // class processor {
            // // public:     inline static void on(wattrel::command::subscription & subscription, uint32 type, wattrel::command::node * node);
            // // public:     inline static void executeOn(wattrel::command::subscription & subscription, wattrel::command::node * node);
            // // public:     inline processor(void);
            // // public:     inline virtual ~processor(void);
            // // public:     processor(const processor & o) = delete;
            // // public:     processor(processor && o) noexcept = delete;
            // // public:     processor & operator=(const processor & o) = delete;
            // // public:     processor & operator=(processor && o) noexcept = delete;
            // };
            //

            class generator : public wattrel::command::generator {
            // public:      template <...> wattrel::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n);
            // public:     virtual wattrel::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n);
            public:     template <class outputable, class objectable = pokemon::generic::command<outputable>>
                        latios::command::subscription<objectable> * reg(objectable * target, uint32 properties, objectable::callback::type * callbacks, uint32 n);
            public:     inline explicit generator(wattrel::engine * engine) : wattrel::command::generator(engine) {}
            public:     generator(void) = delete;
            public:     inline ~generator(void) override {}
            public:     generator(const generator & o) = delete;
            public:     generator(generator && o) noexcept = delete;
            public:     generator & operator=(const generator & o) = delete;
            public:     generator & operator=(generator && o) noexcept = delete;
            };



            //
            //
            // class event : public wattrel::command::event {
            // // public:     typedef pokemon::command::event::type   type;
            // // public:     typedef wattrel::event::subscription    subscription;
            // public:     inline event(uint32 id, latios::command::node * node);
            // public:     event(void) = delete;
            // public:     inline ~event(void) override;
            // public:     event(const event & o) = delete;
            // public:     event(event && o) noexcept = delete;
            // public:     event & operator=(const event & o) = delete;
            // public:     event & operator=(event && o) noexcept = delete;
            // };
            //
            // template <class objectable>
            // class subscription : public wattrel::command::subscription {
            // // public:     struct state : public wattrel::subscription::state {
            // //             public:     constexpr static uint32 none     = wattrel::subscription::state::none;
            // //             public:     constexpr static uint32 complete = wattrel::subscription::state::complete;
            // //             };
            // // protected:  pokemon::command * object;
            // // protected:  wattrel::command::callback callbacks[wattrel::command::event::type::max];
            // public:
            // // public:     inline virtual void del(void);
            // // public:     inline virtual pokemon::command * objectGet(void) const;
            // // public:     inline int dispatch(wattrel::node * o) override;
            // // public:     inline virtual int on(uint32 type, wattrel::command::node & node);
            // // public:     inline int on(uint32 type) override;
            // // public:     inline void raise(pokemon::exception * e) override;
            // // public:     inline void complete(wattrel::node * node) override;
            // // public:     inline bool cancel(void) override;
            // // public:     inline virtual bool completedGet(void) const;
            // // public:     inline virtual void execute(wattrel::command::node * node);
            // // public:     inline explicit subscription(pokemon::command * object, uint32 properties, const wattrel::command::callback::type * callbacks, uint32 n);
            // public:     subscription(void) = delete;
            // public:     inline ~subscription(void) override;
            // public:     subscription(const subscription & o) = delete;
            // public:     subscription(subscription && o) noexcept = delete;
            // public:     subscription & operator=(const subscription & o) = delete;
            // public:     subscription & operator=(subscription && o) noexcept = delete;
            // };

            template <typename objectable>
            class subscription : public virtual wattrel::command::subscription, public latios::subscription<objectable> {
            public:     constexpr static const char * name = "generic subscription";
            public:     typedef objectable      command;
            public:     inline command * objectGet(void) const override { return dynamic_cast<command *>(object); }
            public:     inline explicit subscription(command * object, uint32 properties, const command::callback::type * callbacks, uint32 n) :
                        wattrel::command::subscription(object, properties, reinterpret_cast<wattrel::command::callback::type *>(callbacks), n) {

                        }
            public:     subscription(void) = delete;
            public:     inline ~subscription(void) override {}
            public:     subscription(const subscription & o) = delete;
            public:     subscription(subscription && o) noexcept = delete;
            public:     subscription & operator=(const subscription & o) = delete;
            public:     subscription & operator=(subscription && o) noexcept = delete;
            };


            // template <class objectable>
            // class subscription : public latios::subscription<objectable, typename objectable::output, pokemon::command::tag>, public virtual wattrel::subscription {
            // public:     constexpr static const char * name = "command";   // ### 20250901 | REMOVE THIS FOR DEBUG
            // public:     explicit subscription(uint32 properties) : wattrel::subscription(properties) {}
            // public:     subscription(void) = delete;
            // public:     ~subscription(void) override {}
            // public:     subscription(const subscription & o) = delete;
            // public:     subscription(subscription && o) noexcept = delete;
            // public:     subscription & operator=(const subscription & o) = delete;
            // public:     subscription & operator=(subscription && o) noexcept = delete;
            // };


            //
            // class node : public wattrel::node, public virtual wattrel::command::envelope {
            // // public:     typedef command::envelope::message  message;
            // // public:     inline wattrel::command::event * eventGet(void) const override;
            // // public:     inline explicit node(wattrel::command::subscription * subscription);
            // public:     node(void) = delete;
            // public:     inline ~node(void) override;
            // public:     node(const node & o) = delete;
            // public:     node(node && o) noexcept = delete;
            // public:     node & operator=(const node & o) = delete;
            // public:     node & operator=(node && o) noexcept = delete;
            // public:     friend processor;
            // public:     friend subscription;
            // };

        }

    }
}

#endif // __POKEMONISM_LATIOS_COMMAND_HH__