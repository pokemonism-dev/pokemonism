/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_COMMAND_HH__
#define   __POKEMONISM_WATTREL_COMMAND_HH__

#include <pokemonism/pokemon/command.hh>
#include <pokemonism/pokemon/exception.hh>

#include <pokemonism/wattrel/node.hh>
#include <pokemonism/wattrel/event.hh>
#include <pokemonism/wattrel/generator.hh>
#include <pokemonism/wattrel/subscription.hh>

namespace pokemonism {
    namespace wattrel {
        namespace command {

            typedef pokemon::command::output    output;
            typedef pokemon::command::callback  callback;

            class node;
            class subscription;

            class envelope : public virtual pokemon::command::envelope {
            public:     typedef wattrel::command::output     message;
            protected:  pokemon::exception * exception;
            protected:  int ret;
            protected:  wattrel::command::envelope::message * output;
            public:     inline wattrel::command::envelope::message * pop(void) override;
            public:     inline pokemon::exception * exceptionPop(void) override;
            public:     inline int returnGet(void) const;
            public:     inline envelope(void);
            public:     inline explicit envelope(pokemon::exception * e);
            public:     inline ~envelope(void) override;
            public:     envelope(const envelope & o) = delete;
            public:     envelope(envelope && o) noexcept = delete;
            public:     envelope & operator=(const envelope & o) = delete;
            public:     envelope & operator=(envelope && o) noexcept = delete;
            };

            class processor {
            public:     inline static void on(wattrel::command::subscription & subscription, uint32 type, wattrel::command::node * node);
            public:     inline static void executeOn(wattrel::command::subscription & subscription, wattrel::command::node * node);
            public:     inline processor(void);
            public:     inline virtual ~processor(void);
            public:     processor(const processor & o) = delete;
            public:     processor(processor && o) noexcept = delete;
            public:     processor & operator=(const processor & o) = delete;
            public:     processor & operator=(processor && o) noexcept = delete;
            };

            class generator : public wattrel::generator {
            public:     virtual wattrel::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n);
            public:     inline explicit generator(wattrel::engine * engine);
            public:     generator(void) = delete;
            public:     inline ~generator(void) override;
            public:     generator(const generator & o) = delete;
            public:     generator(generator && o) noexcept = delete;
            public:     generator & operator=(const generator & o) = delete;
            public:     generator & operator=(generator && o) noexcept = delete;
            };

            class event : public virtual pokemon::command::event, public wattrel::event {
            public:     typedef pokemon::command::event::type   type;
            public:     typedef wattrel::event::subscription    subscription;
            public:     inline event(uint32 id, wattrel::command::node * node);
            public:     event(void) = delete;
            public:     inline ~event(void) override;
            public:     event(const event & o) = delete;
            public:     event(event && o) noexcept = delete;
            public:     event & operator=(const event & o) = delete;
            public:     event & operator=(event && o) noexcept = delete;
            };

            class subscription : public virtual wattrel::subscription, public virtual command::event::subscription {
            public:     struct state : public wattrel::subscription::state {
                        public:     constexpr static uint32 none     = wattrel::subscription::state::none;
                        public:     constexpr static uint32 complete = wattrel::subscription::state::complete;
                        };
            protected:  pokemon::command * object;
            protected:  wattrel::command::callback callbacks[wattrel::command::event::type::max];
            public:     inline virtual void del(void);
            public:     inline virtual pokemon::command * objectGet(void) const;
            public:     inline int dispatch(wattrel::node * o) override;
            public:     inline virtual int on(uint32 type, wattrel::command::node & node);
            public:     inline int on(uint32 type) override;
            public:     inline void raise(pokemon::exception * e) override;
            public:     inline void complete(wattrel::node * node) override;
            public:     inline bool cancel(void) override;
            public:     inline virtual bool completedGet(void) const;
            public:     inline virtual void execute(wattrel::command::node * node);
            public:     inline explicit subscription(pokemon::command * object, uint32 properties, const wattrel::command::callback::type * callbacks, uint32 n);
            public:     subscription(void) = delete;
            public:     inline ~subscription(void) override;
            public:     subscription(const subscription & o) = delete;
            public:     subscription(subscription && o) noexcept = delete;
            public:     subscription & operator=(const subscription & o) = delete;
            public:     subscription & operator=(subscription && o) noexcept = delete;
            };

            class node : public wattrel::node, public virtual wattrel::command::envelope {
            public:     typedef command::envelope::message  message;
            public:     inline wattrel::command::event * eventGet(void) const override;
            public:     inline explicit node(wattrel::command::subscription * subscription);
            public:     node(void) = delete;
            public:     inline ~node(void) override;
            public:     node(const node & o) = delete;
            public:     node(node && o) noexcept = delete;
            public:     node & operator=(const node & o) = delete;
            public:     node & operator=(node && o) noexcept = delete;
            public:     friend processor;
            public:     friend subscription;
            };

            inline wattrel::command::envelope::message * envelope::pop(void) {
                wattrel::command::envelope::message * o = output;

                output = nullptr;

                return o;
            }

            pokemon::exception * envelope::exceptionPop(void) {
                pokemon::exception * e = exception;

                exception = nullptr;

                return e;
            }


            int envelope::returnGet(void) const {
                return ret;
            }

            envelope::envelope(void) : exception(nullptr), ret(declaration::success), output(nullptr) {

            }

            inline envelope::envelope(pokemon::exception * e) : exception(e), ret(declaration::fail), output(nullptr) {

            }

            inline envelope::~envelope(void) {
                if (output != nullptr) pokemon::exception::exit("output != nullptr");

                exception = allocator::del(exception);
            }

            inline void processor::on(wattrel::command::subscription & subscription, uint32 type, wattrel::command::node * node) {
                if (type != wattrel::command::event::type::execute) throw pokemon::exception();

                executeOn(subscription, node);
            }

            inline void processor::executeOn(wattrel::command::subscription & subscription, wattrel::command::node * node) {
                subscription.execute(node);

                if (subscription.completedGet()) subscription.del();
            }

            inline processor::processor(void) {

            }

            inline processor::~processor(void) {

            }

            inline generator::generator(wattrel::engine * engine) : wattrel::generator(engine) {

            }

            inline generator::~generator(void) {

            }

            inline event::event(uint32 id, wattrel::command::node * node) : wattrel::event(id, static_cast<wattrel::node *>(node)) {
            }

            inline event::~event(void) {

            }

            inline void subscription::del(void) {
                clear();
                if (container != nullptr) container->del(this);
            }

            inline pokemon::command * subscription::objectGet(void) const {
                return object;
            }

            inline int subscription::dispatch(wattrel::node * o) {
                if (o == nullptr || o->eventGet() == nullptr || object == nullptr) throw pokemon::exception();

                wattrel::command::node * node = dynamic_cast<wattrel::command::node *>(o);

                const wattrel::command::event * event = node->eventGet();
                const uint32 type = event->eventGet();

                if (wattrel::command::event::type::max <= type) throw pokemon::exception();

                try {
                    wattrel::command::processor::on(*this, type, node);
                } catch (const pokemon::exception & e) {
                    node->raise(e.clone());
                } catch (...) {
                    node->raise(new pokemon::exception());
                }

                const command::callback::type func = reinterpret_cast<wattrel::command::callback::type>(callbacks[type].func);

                return func != nullptr ? func(*object, type, node) : declaration::fail;

            }

            inline int subscription::on(uint32 type, command::node & node) {
                if (command::event::type::max <= type || object == nullptr) throw pokemon::exception();

                const command::callback::type func = reinterpret_cast<command::callback::type>(callbacks[type].func);

                return func != nullptr ? func(*object, type, pointof(node)) : declaration::fail;
            }

            inline int subscription::on(uint32 type) {
                if (command::event::type::max <= type || object == nullptr) throw pokemon::exception();

                const command::callback::type func = reinterpret_cast<command::callback::type>(callbacks[type].func);

                return func != nullptr ? func(*object, type, nullptr) : declaration::fail;
            }

            inline void subscription::raise(pokemon::exception * e) {
                if (object == nullptr) throw pokemon::exception();

                if (const command::callback::type func = reinterpret_cast<command::callback::type>(callbacks[command::event::type::exception].func); func != nullptr) {
                    command::envelope envelope(e);

                    func(*object, command::event::type::exception, pointof(envelope));
                }
            }

            inline void subscription::complete(wattrel::node * node) {

            }

            inline bool subscription::completedGet(void) const {
                return (status & wattrel::command::subscription::state::complete) != wattrel::command::subscription::state::none;
            }

            inline void subscription::execute(wattrel::command::node * node) {
                if (node == nullptr || node->output != nullptr || object == nullptr) throw pokemon::exception();

                node->output = (*object)();

                status = status | wattrel::command::subscription::state::complete;
            }

            inline bool subscription::cancel(void) {
                clear();
                if (container != nullptr) {
                    if (properties & wattrel::command::subscription::property::release_on_del) {
                        properties = (properties & (~wattrel::command::subscription::property::release_on_del));
                        // ### 20250831 | 사용자가 설정한 값인데, 사용자가 CANCEL 을 해주면, 삭제가 되면서, 객체가 남아 있기 때문에, 삭제 시 제거 속성을 없애주어야 한다.
                        //              | 대신 로그로 사용자에게 알려주자.
                    }

                    container->del(this);

                    return true;
                }
                return false;
            }

            inline subscription::subscription(pokemon::command * object, uint32 properties, const command::callback::type * callbacks, uint32 n)
            : wattrel::subscription(properties), object(object), callbacks() {
                if (callbacks == nullptr || n == 0 || n > command::event::type::max) throw pokemon::exception();

                memcpy(this->callbacks, callbacks, sizeof(command::callback::type) * n);
                if (n < command::event::type::max) memset(this->callbacks + n, 0, (command::event::type::max - n) * sizeof(command::callback::type));
            }

            inline subscription::~subscription(void) {
                on(wattrel::command::event::type::rel);
                object = (properties & property::release_object_on_rel ? allocator::del(object) : nullptr);
                memset(this->callbacks, 0, sizeof(command::callback::type) * command::event::type::max);
            }

            inline wattrel::command::event * node::eventGet(void) const {
                return dynamic_cast<command::event *>(event);
            }

            inline node::node(wattrel::command::subscription * subscription) : wattrel::node(static_cast<wattrel::subscription *>(subscription)) {

            }

            inline node::~node(void) {

            }

        }
    }
}

#endif // __POKEMONISM_WATTREL_COMMAND_HH__
