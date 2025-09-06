/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SDK_EVENT_HH__
#define   __POKEMONISM_SDK_EVENT_HH__

#include <pokemonism/sdk/sync.hh>
#include <pokemonism/sdk/runnable.hh>
#include <pokemonism/sdk/envelopeable.hh>
#include <pokemonism/sdk/callbackable.hh>
#include <pokemonism/sdk/subscription.hh>
#include <pokemonism/sdk/linked/list.hh>

namespace pokemonism::sdk {

    class engine;

    class event {
    public:     class link;
    public:     struct type;
    public:     class queue;
    public:     class envelope;
    public:     class generator;
    public:     class processor;
    public:     class subscription;
    public:     struct modifiable;
    public:     struct releasable;
    public:     struct internal;
    public:     using exception = pokemonism::sdk::exception;
    protected:  inline static event * dispatch(event * e);
    protected:  static event * rem(event * e);
    protected:  event::queue *  container;
    protected:  event *         prev;
    protected:  event *         next;
    protected:  event::link *   node;
    protected:  unsigned int    identifier;
    protected:  inline int on(void) const;
    protected:  inline virtual void reset(void);
    public:     inline unsigned int identifierGet(void) const { return identifier; }
    public:     inline event(unsigned int identifier, event::link * node);
    public:     event(void) = delete;
    public:     inline virtual ~event(void);
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    public:     friend linked::list<event::queue, event>;
    };

    struct event::type {
    public:     constexpr static unsigned int max = 0;
    };

    class event::queue : public pokemonism::sdk::sync {
    public:     using collection = linked::list<event::queue, event>;
    protected:  unsigned long size;
    protected:  event * head;
    protected:  event * tail;
    public:     unsigned long on(unsigned long n = declaration::infinite);
    public:     event * add(event * e);
    public:     event * del(event * e);
    public:     void clear(void);
    public:     inline queue(void);
    public:     inline ~queue(void) override;
    public:     queue(const event::queue & o) = delete;
    public:     queue(event::queue && o) noexcept = delete;
    public:     event::queue & operator=(const event::queue & o) = delete;
    public:     event::queue & operator=(event::queue && o) noexcept = delete;
    public:     friend collection;
    };

    struct event::modifiable {
    public:     class subscription;
    };

    struct event::releasable {
    public:     class subscription;
    };

    class event::subscription : public pokemonism::sdk::subscription, public sync {
    public:     using collection = linked::list<event::subscription, event::link>;
    public:     struct state {
                public:     struct type {
                            public:     constexpr static unsigned int gen = 0;
                            public:     constexpr static unsigned int add = 1;
                            public:     constexpr static unsigned int chk = 2;
                            public:     constexpr static unsigned int del = 3;
                            public:     constexpr static unsigned int rel = 4;
                            public:     constexpr static unsigned int max = 5;
                            };
                public:     constexpr static unsigned int gen       = (0x00000001U <<  0U);
                public:     constexpr static unsigned int add       = (0x00000001U <<  1U);
                public:     constexpr static unsigned int exception = (0x00000001U <<  4U);
                public:     constexpr static unsigned int complete  = (0x00000001U <<  5U);
                public:     constexpr static unsigned int cancel    = (0x00000001U <<  6U);
                public:     struct callback : public callbackable {
                            public:     typedef void (*function)(event::modifiable::subscription &, unsigned int, const event::exception *);
                            public:     typedef void (*modifier)(event::releasable::subscription &, unsigned int, const event::exception *);
                            public:     inline callback(void) {}
                            public:     inline explicit callback(event::subscription::state::callback::function f) : callbackable(reinterpret_cast<callbackable::function>(f)) {}
                            public:     inline ~callback(void) { func = nullptr; }
                            public:     struct set {
                                        public:     event::subscription::state::callback::function on;
                                        public:     event::subscription::state::callback::modifier rel;
                                        public:     inline set(void) : on(nullptr), rel(nullptr) {}
                                        public:     inline explicit set(event::subscription::state::callback::function on) : on(on), rel(nullptr) {}
                                        public:     inline explicit set(event::subscription::state::callback::modifier rel) : on(nullptr), rel(rel) {}
                                        public:     inline explicit set(event::subscription::state::callback::function on, event::subscription::state::callback::modifier rel) : on(on), rel(rel) {}
                                        };
                            };
                };
    public:     struct property {
                public:     constexpr static unsigned int release_on_del        = (0x00000001U << 31U);
                public:     constexpr static unsigned int release_object_on_rel = (0x00000001U << 31U);
                };
    protected:  class releaser : public runnable::queue::node {
                protected:  event::subscription * subscription;
                public:     inline void operator()(void) override {
                                delete subscription;
                                subscription = nullptr;
                            }
                public:     inline explicit releaser(event::subscription * subscription) : subscription(subscription) {
                                pokemon_develop_check(subscription == nullptr, return);
                            }
                public:     inline releaser(void) = delete;
                public:     inline ~releaser(void) override {
                                if (subscription != nullptr) {
                                    delete subscription;
                                    subscription = nullptr;
                                }
                            }
                public:     releaser(const event::subscription::releaser & o) = delete;
                public:     releaser(event::subscription::releaser && o) noexcept = delete;
                public:     event::subscription::releaser & operator=(const event::subscription::releaser & o) = delete;
                public:     event::subscription::releaser & operator=(event::subscription::releaser && o) noexcept = delete;
                };
    protected:  unsigned long                               size;
    protected:  event::link *                               head;
    protected:  event::link *                               tail;
    protected:  event::generator *                          container;
    protected:  event::subscription *                       prev;
    protected:  event::subscription *                       next;
    protected:  unsigned int                                properties;
    protected:  unsigned int                                status;
    protected:  event::subscription::state::callback::set   stateSet;
    protected:  event::exception *                          exception;
    public:     inline virtual bool propertyChk(unsigned int flag) const;
    public:     inline virtual bool completeChk(void) const;
    public:     inline virtual bool cancelChk(void) const;
    public:     inline virtual bool finishChk(void) const;
    public:     inline virtual bool exceptionChk(void) const;
    public:     inline virtual bool stateChk(unsigned int state) const;
    protected:  inline int lock(void) noexcept override { return sync::lock(); }
    protected:  inline int unlock(void) noexcept override { return sync::unlock(); }
    protected:  inline int wait(void) noexcept override { return sync::wait(); }
    protected:  inline int wakeup(void) noexcept override { return sync::wakeup(); }
    protected:  inline int wait(long second, long nano) noexcept override { return sync::wait(second, nano); }
    protected:  inline int wakeup(bool all) noexcept override { return sync::wakeup(all); }
    protected:  virtual void stateOn(unsigned int type, const event::exception * problem = nullptr) = 0;
    public:     virtual int processOn(unsigned int type) = 0;
    protected:  virtual int processOn(event::link * link) = 0;
    protected:  virtual void callbackOn(unsigned int type, const event::exception * problem = nullptr) = 0;
    protected:  virtual void callbackOn(unsigned int type, event::envelope & envelope, const event::exception * problem = nullptr) = 0;
    protected:  virtual void raise(event::link * link, event::exception * problem);
    protected:  inline void containerDel(void);
    public:     bool cancel(void) override;
    protected:  event::link * add(event::link * link);
    protected:  event::link * del(event::link * link);
    protected:  void clear(void);
    protected:  inline explicit subscription(unsigned int properties);
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::function subscriptionOn);
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::modifier subscriptionReleaseOn);
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::function subscriptionOn, event::subscription::state::callback::modifier subscriptionReleaseOn);
    protected:  inline subscription(void);
    public:     inline ~subscription(void) override;
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    public:     friend collection;
    public:     friend linked::list<event::generator, event::subscription>;
    public:     friend event::generator;
    public:     friend event::link;
    };

    class event::modifiable::subscription : public virtual event::subscription {
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::function subscriptionOn) : event::subscription(properties, subscriptionOn) {}
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::modifier subscriptionReleaseOn) : event::subscription(properties, subscriptionReleaseOn) {}
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::function subscriptionOn, event::subscription::state::callback::modifier subscriptionReleaseOn) : event::subscription(properties, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) {}
    protected:  inline ~subscription(void) override {}
    };

    class event::releasable::subscription : public virtual event::modifiable::subscription {
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::function subscriptionOn) : event::modifiable::subscription(properties, subscriptionOn) {}
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::modifier subscriptionReleaseOn) : event::modifiable::subscription(properties, subscriptionReleaseOn) {}
    protected:  inline subscription(unsigned int properties, event::subscription::state::callback::function subscriptionOn, event::subscription::state::callback::modifier subscriptionReleaseOn) : event::modifiable::subscription(properties, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) {}
    protected:  inline ~subscription(void) override {}
    };

    struct event::internal {
    public:     class subscription : public virtual event::releasable::subscription {
                protected:  void stateOn(unsigned int type, const event::exception * problem = nullptr) override;
                protected:  inline subscription(unsigned int properties, event::subscription::state::callback::function subscriptionOn) : event::releasable::subscription(properties, subscriptionOn) {}
                protected:  inline subscription(unsigned int properties, event::subscription::state::callback::modifier subscriptionReleaseOn) : event::releasable::subscription(properties, subscriptionReleaseOn) {}
                protected:  inline subscription(unsigned int properties, event::subscription::state::callback::function subscriptionOn, event::subscription::state::callback::modifier subscriptionReleaseOn) : event::releasable::subscription(properties, subscriptionOn, subscriptionReleaseOn) {}
                protected:  inline subscription(void) {}
                public:     inline ~subscription(void) override {}
                };
    };

    class event::envelope : public envelopeable {
    protected:  event::exception * exception;
    protected:  event::subscription * container;
    public:     inline const event::exception * exceptionGet(void) const;
    public:     inline virtual event::subscription * subscriptionGet(void) const;
    protected:  virtual void reset(void) = 0;
    public:     inline explicit envelope(event::subscription * container, event::exception * exception = nullptr);
    protected:  inline envelope(void);
    protected:  inline ~envelope(void) override;
    public:     envelope(const event::envelope & o) = delete;
    public:     envelope(event::envelope && o) noexcept = delete;
    public:     event::envelope & operator=(const event::envelope & o) = delete;
    public:     event::envelope & operator=(event::envelope && o) noexcept = delete;
    };

    class event::link : public virtual event::envelope {
    public:     static event::link * rem(event::link * o);
    protected:  event::link * prev;
    protected:  event::link * next;
    protected:  event * e;
    public:     inline unsigned int identifierGet(void) const;
    public:     inline event::exception * exceptionSet(event::exception * problem);
    public:     inline int on(void);
    public:     inline void raise(event::exception * exception);
    public:     inline explicit link(event::subscription * container);
    public:     link(void) = delete;
    public:     inline ~link(void) override;
    public:     link(const event::link & o) = delete;
    public:     link(event::link && o) noexcept = delete;
    public:     event::link & operator=(const event::link & o) = delete;
    public:     event::link & operator=(event::link && o) noexcept = delete;
    public:     friend event;
    public:     friend linked::list<event::subscription, event::link>;
    };

    class event::processor {
    public:     processor(void) {}
    public:     virtual ~processor(void) {}
    public:     processor(const event::processor & o) = delete;
    public:     processor(event::processor && o) noexcept = delete;
    public:     event::processor & operator=(const event::processor & o) = delete;
    public:     event::processor & operator=(event::processor && o) noexcept = delete;
    };

    class event::generator : public sync {
    public:     using collection = linked::list<event::generator, event::subscription>;
    protected:  unsigned long size;
    protected:  event::subscription * head;
    protected:  event::subscription * tail;
    protected:  engine * engine;
    protected:  runnable::queue queue;
    protected:  event::subscription * add(event::subscription * subscription);
    protected:  event::subscription * del(event::subscription * subscription);
    protected:  runnable::queue::node * add(runnable::queue::node * f);
    protected:  runnable::queue::node * del(runnable::queue::node * f);
    protected:  void clear(void);
    protected:  explicit generator(pokemonism::sdk::engine * engine);
    public:     generator(void) = delete;
    protected:  ~generator(void) override;
    public:     generator(const event::generator & o) = delete;
    public:     generator(event::generator && o) noexcept = delete;
    public:     event::generator & operator=(const event::generator & o) = delete;
    public:     event::generator & operator=(event::generator && o) noexcept = delete;
    public:     friend collection;
    public:     friend event::subscription;
    };

    inline event * event::dispatch(event * e) {
        pokemon_develop_check(e == nullptr, return e);

        if (e->on() > declaration::success) {
            e->reset();
            return e;
        }

        delete e;

        return nullptr;
    }

    inline void event::reset(void) {
        pokemon_develop_check(node == nullptr, return);

        node->reset();
    }

    inline int event::on(void) const {
        pokemon_develop_check(node == nullptr, return declaration::fail);

        return node->on();
    }

    inline event::event(unsigned int identifier, event::link * node) : container(nullptr), prev(nullptr), next(nullptr), node(node), identifier(identifier) {
        pokemon_develop_check(node == nullptr, return);

        node->e = this;
    }

    inline event::~event(void) {
        event::rem(this);
    }

}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/sdk/event/link.hh>
#include <pokemonism/sdk/event/queue.hh>
#include <pokemonism/sdk/event/engine.hh>
#include <pokemonism/sdk/event/envelope.hh>
#include <pokemonism/sdk/event/generator.hh>
#include <pokemonism/sdk/event/subscription.hh>

// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_SDK_EVENT_HH__
