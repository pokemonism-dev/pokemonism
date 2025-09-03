/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_COMMAND_HH__
#define   __POKEMONISM_GARDEVOIR_COMMAND_HH__

#include <pokemonism/pokemon/exception.hh>

#include <pokemonism/ralts/kirlia/command.hh>
#include <pokemonism/ralts/kirlia/gardevoir/event.hh>
#include <pokemonism/ralts/kirlia/gardevoir/envelope.hh>
#include <pokemonism/ralts/kirlia/gardevoir/generator.hh>
#include <pokemonism/ralts/kirlia/gardevoir/subscription.hh>

#include <pokemonism/ralts/kirlia/gallade/command.hh>

#include "command.hh"

namespace pokemonism {
    namespace gardevoir {
        namespace command {

            class node;
            class process;
            class generator;
            class subscription;

            class event : public gardevoir::event, public kirlia::command::event {
            public:     struct type : public kirlia::command::event::type {};
            public:     struct handler : public pokemon::command::event::handler {};
            public:     class subscription : public kirlia::command::subscription {
                        public:     subscription(void) {}
                        public:     ~subscription(void) override {}
                        public:     subscription(const gardevoir::command::event::subscription & o) = delete;
                        public:     subscription(gardevoir::command::event::subscription && o) noexcept = delete;
                        public:     gardevoir::command::event::subscription & operator=(const gardevoir::command::event::subscription & o) = delete;
                        public:     gardevoir::command::event::subscription & operator=(gardevoir::command::event::subscription && o) noexcept = delete;
                        };
            public:     event(uint32 id, gardevoir::command::node * node);
            public:     event(void) = delete;
            public:     ~event(void) override {}
            public:     event(const gardevoir::command::event & o) = delete;
            public:     event(gardevoir::command::event && o) noexcept = delete;
            public:     gardevoir::command::event & operator=(const gardevoir::command::event & o) = delete;
            public:     gardevoir::command::event & operator=(gardevoir::command::event && o) noexcept = delete;
            };

            class envelope : public virtual gardevoir::envelope, public kirlia::command::envelope {
            public:     typedef kirlia::command::envelope::message  message;
            protected:  message * output;
            public:     inline pokemon::exception * exceptionPop(void) override;
            public:     inline kirlia::command::envelope::message * messagePop() override;
            public:     inline void messageSet(kirlia::command::envelope::message * o);
            public:     inline envelope(void);
            public:     inline ~envelope(void) override;
            public:     envelope(const gardevoir::command::envelope & o) = delete;
            public:     envelope(gardevoir::command::envelope & o) noexcept = delete;
            public:     gardevoir::command::envelope & operator=(const gardevoir::command::envelope & o) = delete;
            public:     gardevoir::command::envelope & operator=(gardevoir::command::envelope & o) noexcept = delete;
            };

            class processor {
            public:     inline static int on(gardevoir::command::subscription & subscription, uint32 type, gardevoir::command::envelope & envelope);
            public:     inline static int on(gardevoir::command::subscription & subscription, uint32 type);
            public:     processor(void) {}
            public:     virtual ~processor(void) {}
            public:     processor(const gardevoir::command::processor & o) = delete;
            public:     processor(gardevoir::command::processor && o) noexcept = delete;
            public:     gardevoir::command::processor & operator=(const gardevoir::command::processor & o) = delete;
            public:     gardevoir::command::processor & operator=(gardevoir::command::processor && o) noexcept = delete;
            public:     friend gardevoir::command::envelope;
            };

            class node : public gardevoir::node, public gardevoir::command::envelope {
            public:     inline void exceptionSet(pokemon::exception * e);
            public:     inline gardevoir::command::event * eventGet(void) const override;
            public:     inline explicit node(gardevoir::command::subscription * subscription);
            public:     inline node(void) = delete;
            public:     inline node(const gardevoir::command::node & o) = delete;
            public:     inline node(gardevoir::command::node && o) noexcept = delete;
            public:     gardevoir::command::node & operator=(const gardevoir::command::node & o) = delete;
            public:     gardevoir::command::node & operator=(gardevoir::command::node && o) noexcept = delete;
            public:     friend gardevoir::command::subscription;
            };

            class subscription : public kirlia::command::poppable::subscription, public gardevoir::subscription {
            public:     struct event : public kirlia::command::subscription::event {
                        public:     struct handler : public pokemon::functionable {
                                    public:     typedef void (*type)(const kirlia::command::subscription &, uint32, const pokemon::exception *);
                                    public:     typedef gardevoir::command::subscription::event::handler::type     set[gardevoir::command::subscription::event::type::max];
                                    };
                        };
            public:     struct property : public kirlia::command::poppable::subscription::property {
                        public:     struct mask {
                                    public:     constexpr static uint32 type        = kirlia::command::type::max;
                                    };
                        public:     constexpr static uint32 release_object_on_rel   = kirlia::command::poppable::subscription::property::release_object_on_rel;
                        public:     constexpr static uint32 release_on_del          = kirlia::command::poppable::subscription::property::release_on_del;
                        };
            protected:  gardevoir::command::event::handler::set eventSet;
            protected:  pokemon::command * object;
            public:     int on(gardevoir::node * node) override;
            public:     inline void on(uint32 type, pokemon::exception * e = nullptr) override;
            public:     inline void raise(gardevoir::node * node) override;
            public:     inline gardevoir::command::generator * containerGet(void) const;
            public:     inline bool cancel(void) override { return gardevoir::subscription::cancel(); }
            public:     inline virtual void eventOn(gardevoir::command::node * node);
            public:     inline virtual void eventOn(uint32 type, gardevoir::command::envelope * envelope);
            public:     inline pokemon::command * commandGet(void) const override;
            public:     inline pokemon::command * commandPop(void) override;
            public:     inline virtual void executeSet(void);
            public:     inline explicit subscription(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & handlerSet);
            public:     inline subscription(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & handlerSet, const gardevoir::command::subscription::event::handler::set & subscriptionSet);
            public:     subscription(void) = delete;
            public:     ~subscription(void) override;
            public:     subscription(const gardevoir::command::subscription & o) = delete;
            public:     subscription(gardevoir::command::subscription && o) noexcept = delete;
            public:     gardevoir::command::subscription & operator=(const gardevoir::command::subscription & o) = delete;
            public:     gardevoir::command::subscription & operator=(gardevoir::command::subscription && o) noexcept = delete;
            public:     friend gardevoir::command::node;
            };

            class generator : public gardevoir::generator {
            public:     virtual gardevoir::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet);
            public:     virtual gardevoir::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet, const gardevoir::command::subscription::event::handler::set & subscriptionSet);
            public:     virtual gardevoir::command::subscription * reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet);
            public:     virtual gardevoir::command::subscription * reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet, const gardevoir::command::subscription::event::handler::set & subscriptionSet);
            public:     inline uint64 on(void) override;
            public:     inline explicit generator(gardevoir::engine * engine);
            public:     inline ~generator(void) override;
            public:     generator(const gardevoir::command::generator & o) = delete;
            public:     generator(gardevoir::command::generator && o) noexcept = delete;
            public:     gardevoir::command::generator & operator=(const gardevoir::command::generator & o) = delete;
            public:     gardevoir::command::generator & operator=(gardevoir::command::generator && o) noexcept = delete;
            };

            namespace repeat {
                class subscription : public gardevoir::command::subscription {
                public:     int32 count;
                public:     int32 total;
                public:     inline void executeSet(void) override {
                                if (total >= 0) {
                                    count = count + 1;
                                    if (total <= count) {
                                        status = status | gardevoir::command::subscription::state::complete;
                                    }
                                }
                            }
                public:     subscription(void);
                public:     ~subscription(void) override {}
                public:     inline explicit subscription(pokemon::command * target, int32 total, uint32 properties, const pokemon::command::event::handler::set & handlerSet) : gardevoir::command::subscription(target, properties, handlerSet), count(0), total(total) {}
                public:     inline subscription(pokemon::command * target, int32 total, uint32 properties, const pokemon::command::event::handler::set & handlerSet, const gardevoir::command::subscription::event::handler::set & subscriptionSet) : gardevoir::command::subscription(target, properties, handlerSet, subscriptionSet), count(0), total(total) {}
                public:     subscription(const gardevoir::command::repeat::subscription & o) = delete;
                public:     subscription(gardevoir::command::repeat::subscription && o) noexcept = delete;
                public:     gardevoir::command::repeat::subscription & operator=(const gardevoir::command::repeat::subscription & o) = delete;
                public:     gardevoir::command::repeat::subscription & operator=(gardevoir::command::repeat::subscription && o) noexcept = delete;
                };
            }

            inline event::event(uint32 id, gardevoir::command::node * node) : gardevoir::event(id, node) {

            }

            inline pokemon::exception * envelope::exceptionPop(void) {
                return gardevoir::envelope::exceptionPop();
            }

            inline kirlia::command::envelope::message * envelope::messagePop() {
                kirlia::command::envelope::message * o = output;
                output = nullptr;
                return o;
            }

            inline void envelope::messageSet(kirlia::command::envelope::message * o) {
                pokemon_develop_check(output != nullptr, return);
                output = o;
            }

            inline envelope::envelope(void) : output(nullptr) {

            }

            inline envelope::~envelope(void) {
                pokemon_critical_exit_check(output != nullptr, output = nullptr);
            }

            inline int processor::on(gardevoir::command::subscription & subscription, uint32 type) {
                pokemon_develop_check(gardevoir::command::event::type::max <= type || subscription.commandGet() == nullptr || subscription.finishChk(), return declaration::fail);

                gardevoir::command::envelope envelope;

                return processor::on(subscription, type, envelope);
            }

            inline int processor::on(gardevoir::command::subscription & subscription, uint32 type, gardevoir::command::envelope & envelope) {
                pokemon_develop_check(gardevoir::command::event::type::max <= type || subscription.commandGet() == nullptr || subscription.finishChk(), return declaration::fail);

                pokemon::command & command = referenceof(subscription.commandGet());

                envelope.messageSet(command());
                subscription.executeSet();

                return subscription.completeChk() ? gardevoir::event::success : gardevoir::event::again;
            }

            inline void node::exceptionSet(pokemon::exception * e) {
                pokemon_develop_check(e == nullptr || container == nullptr, return);

                exception = allocator::del(exception);
                exception = e;

                container->exceptionSet();
            }

            inline gardevoir::command::event * node::eventGet(void) const {
                pokemon_develop_check(event == nullptr || gardevoir::command::event::type::max <= event->eventGet(), return nullptr);

                return reinterpret_cast<gardevoir::command::event *>(event);
            }

            inline node::node(gardevoir::command::subscription * subscription) : gardevoir::node(subscription) {

            }

            inline void subscription::on(uint32 type, pokemon::exception * e) {
                gardevoir::subscription::on(type, e);
            }

            inline void subscription::raise(gardevoir::node * node) {
                pokemon_develop_check(node->exceptionGet() == nullptr, return);

                exceptionSet();

                on(node);
            }

            inline gardevoir::command::generator * subscription::containerGet(void) const {
                pokemon_develop_check(container != nullptr && dynamic_cast<gardevoir::command::generator *>(container) == nullptr, return nullptr);

                return reinterpret_cast<gardevoir::command::generator *>(container);
            }

            inline void subscription::eventOn(gardevoir::command::node * node) {
                pokemon_develop_check(node == nullptr || node->subscriptionGet() != this || node->eventGet() == nullptr, return);

                const gardevoir::command::event * event = node->eventGet();

                eventOn(event->eventGet(), node);
            }

            inline void subscription::eventOn(uint32 type, gardevoir::command::envelope * envelope) {
                pokemon_develop_check(gardevoir::command::event::type::max <= type, return);

                if (const gardevoir::command::event::handler::type func = eventSet[type]; func != nullptr) {
                    func(*object, type, envelope);
                }
            }

            inline pokemon::command * subscription::commandGet(void) const {
                return object;
            }

            inline pokemon::command * subscription::commandPop(void) {
                pokemon::command * command = object;
                object = nullptr;
                return command;
            }

            void subscription::executeSet(void) {
                status = status | gardevoir::command::subscription::state::complete;
            }

            inline subscription::subscription(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & handlerSet)
            : gardevoir::subscription(properties), object(target) {
                memcpy(eventSet, handlerSet, sizeof(pokemon::command::event::handler::set));

                pokemon_develop_check(object == nullptr, exit(0));
            }

            inline subscription::subscription(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & handlerSet, const gardevoir::command::subscription::event::handler::set & subscriptionSet)
            : gardevoir::subscription(properties, reinterpret_cast<const gardevoir::subscription::event::handler::set &>(subscriptionSet)), object(target) {
                memcpy(eventSet, handlerSet, sizeof(pokemon::command::event::handler::set));

                pokemon_develop_check(object == nullptr, exit(0));
            }

            inline uint64 generator::on(void) {
                return queue.on();
            }

            inline generator::generator(gardevoir::engine * engine) : gardevoir::generator(engine) {

            }

            generator::~generator(void) {

            }

        }
    }
}

#endif // __POKEMONISM_GARDEVOIR_COMMAND_HH__
