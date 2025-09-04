/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_HH__
#define   __POKEMONISM_PETILIL_HH__

#include <pokemonism/event.hh>
#include <pokemonism/subscription.hh>
#include <pokemonism/generic/envelope.hh>

#include <pokemonism/runnable.hh>
#include <pokemonism/commandable.hh>
#include <pokemonism/callbackable.hh>

#include <pokemonism/pokemon.hh>
#include <pokemonism/psyduck.hh>

namespace pokemonism {

    // ### TODO: IMPLEMENT THIS
    class petilil : public pokemon {
    public:     constexpr static const char * tag = "petilil";
    public:     typedef void (*cleaner)(petilil *);
    public:     class event : public pokemonism::event {
                public:     class link;
                public:     class queue;
                public:     class engine;           // ### TODO | DEFINE THIS
                public:     class envelope;
                public:     struct callback;
                public:     class generator;
                public:     class processor;
                public:     class subscription;
                public:     struct modifiable;
                public:     static petilil::event * rem(petilil::event * event);
                public:     static inline petilil::event * dispatch(petilil::event * event);
                protected:  petilil::event::queue *     container;
                protected:  petilil::event *            prev;
                protected:  petilil::event *            next;
                protected:  petilil::event::link *      node;
                protected:  unsigned int                identifier;
                public:     inline unsigned int identifierGet(void) const override;
                public:     inline virtual int on(void);
                protected:  inline event(unsigned int identifier, petilil::event::link * node);
                protected:  inline event(void);
                public:     inline ~event(void) override;
                public:     event(const petilil::event & o) = delete;
                public:     event(petilil::event && o) noexcept = delete;
                public:     petilil::event & operator=(const petilil::event & o) = delete;
                public:     petilil::event & operator=(petilil::event && o) noexcept = delete;
                public:     friend psyduck::linked::list<petilil::event::queue, petilil::event>;
                };
    public:     struct commandable;
    public:     struct command;
    public:     static petilil * go(void);
    protected:  petilil::cleaner clean;
    protected:  petilil::event::engine * engine;
    public:     inline const char * name(void) const noexcept override;
    public:     inline void recall(petilil::cleaner f);
    public:     virtual petilil * start(void);
    protected:  petilil(void);
    protected:  ~petilil(void) override;
    public:     petilil(const petilil & o) = delete;
    public:     petilil(petilil && o) noexcept = delete;
    public:     petilil & operator=(const petilil & o) = delete;
    public:     petilil & operator=(petilil && o) noexcept = delete;
    };

    class petilil::event::processor {
    public:     processor(void) {}
    public:     virtual ~processor(void) {}
    public:     processor(const petilil::event::processor & o) = delete;
    public:     processor(petilil::event::processor && o) noexcept = delete;
    public:     petilil::event::processor & operator=(const petilil::event::processor & o) = delete;
    public:     petilil::event::processor & operator=(petilil::event::processor && o) noexcept = delete;
    };

    class petilil::event::queue : public sync {
    public:     using collection = psyduck::linked::list<petilil::event::queue, petilil::event>;
    protected:  unsigned long size;
    protected:  petilil::event * head;
    protected:  petilil::event * tail;
    public:     petilil::event * add(petilil::event * event);
    public:     petilil::event * del(petilil::event * event);
    public:     void clear(void);
    public:     virtual unsigned long on(unsigned long n = declaration::infinite);
    public:     inline queue(void);
    public:     inline ~queue(void) override;
    public:     queue(const petilil::event::queue & o) = delete;
    public:     queue(petilil::event::queue && o) noexcept = delete;
    public:     petilil::event::queue & operator=(const petilil::event::queue & o) = delete;
    public:     petilil::event::queue & operator=(petilil::event::queue && o) noexcept = delete;
    public:     friend collection;
    };

    struct petilil::event::callback : public callbackable {
    public:     callback() {}
    public:     explicit callback(callbackable::function f) : callbackable(f) {}
    };

    class petilil::event::envelope : public virtual pokemonism::envelopeable {
    protected:  petilil::event::subscription *  container;
    protected:  pokemon::faint *                exception;
    protected:  int                             ret;
    public:     inline virtual petilil::event::subscription * subscriptionGet(void) const;
    public:     inline virtual const pokemon::faint * exceptionGet(void) const;
    public:     inline int returnGet(void) const;
    public:     inline explicit envelope(petilil::event::subscription * subscription, int ret);
    public:     inline envelope(petilil::event::subscription * subscription, int ret, pokemon::faint * exception);
    public:     inline envelope(void);
    public:     inline ~envelope(void) override;
    public:     envelope(const petilil::event::envelope & o) = delete;
    public:     envelope(petilil::event::envelope && o) noexcept = delete;
    public:     petilil::event::envelope & operator=(const petilil::event::envelope & o) = delete;
    public:     petilil::event::envelope & operator=(petilil::event::envelope && o) noexcept = delete;
    };

    class petilil::event::link : public petilil::event::envelope {
    public:     static petilil::event::link * rem(petilil::event::link * o);
    protected:  petilil::event::link *  prev;
    protected:  petilil::event::link *  next;
    protected:  petilil::event *        event;
    public:     virtual void raise(pokemon::faint * e);
    public:     inline unsigned int identifierGet(void) const;
    public:     inline void returnSet(int v);
    public:     inline virtual int on(void);
    public:     inline explicit link(petilil::event::subscription * subscription);
    public:     inline link(void);
    public:     inline ~link(void) override;
    public:     link(const petilil::event::link & o) = delete;
    public:     link(petilil::event::link && o) noexcept = delete;
    public:     petilil::event::link & operator=(const petilil::event::link & o) = delete;
    public:     petilil::event::link & operator=(petilil::event::link && o) noexcept = delete;
    public:     friend psyduck::linked::list<petilil::event::subscription, petilil::event::link>;
    public:     friend petilil::event;
    };

    struct petilil::event::modifiable {
    public:     class subscription;
    };

    class petilil::event::subscription : public pokemonism::subscription {
    public:     struct property {
                public:     constexpr static unsigned int mask                  = (0x00000FFFU <<  0U);
                public:     constexpr static unsigned int release_object_on_rel = (0x00000001U << 30U);
                public:     constexpr static unsigned int release_on_del        = (0x00000001U << 31U);
                };
    public:     struct state {
                public:     struct type {
                            public:     constexpr static unsigned int gen = 0U;
                            public:     constexpr static unsigned int add = 1U;
                            public:     constexpr static unsigned int chk = 2U;
                            public:     constexpr static unsigned int del = 3U;
                            public:     constexpr static unsigned int rel = 4U;
                            public:     constexpr static unsigned int max = 5U;
                            };
                public:     constexpr static unsigned int min       = (0x00000001U <<  0U);
                public:     constexpr static unsigned int gen       = (0x00000001U <<  0U);
                public:     constexpr static unsigned int add       = (0x00000001U <<  1U);
                public:     constexpr static unsigned int chk       = (0x00000001U <<  2U);
                public:     constexpr static unsigned int del       = (0x00000001U <<  3U);
                public:     constexpr static unsigned int rel       = (0x00000001U <<  4U);
                public:     constexpr static unsigned int cancel    = (0x00000001U <<  5U);
                public:     constexpr static unsigned int complete  = (0x00000001U <<  6U);
                public:     constexpr static unsigned int faint     = (0x00000001U <<  7U);
                public:     constexpr static unsigned int max       = (0x00000001U << 31U);
                };
    public:     struct callback : public callbackable {
                public:     typedef void (*function)(const petilil::event::subscription &, unsigned int, const pokemon::faint * e);
                public:     typedef void (*modifier)(petilil::event::modifiable::subscription &, unsigned int, const pokemon::faint * e);
                public:     struct set {
                            public:     petilil::event::subscription::callback::function on;
                            public:     petilil::event::subscription::callback::modifier rel;
                            public:     inline set(void);
                            public:     inline explicit set(petilil::event::subscription::callback::function on);
                            public:     inline explicit set(petilil::event::subscription::callback::modifier rel);
                            public:     inline set(petilil::event::subscription::callback::function on, petilil::event::subscription::callback::modifier rel);
                            public:     inline ~set(void);
                            };
                };
    public:     class releaser : public runnable::queue::node {
                protected:  petilil::event::subscription * subscription;
                public:     inline void operator()(void) override {
                                if (subscription != nullptr) {
                                    delete subscription;
                                    subscription = nullptr;
                                }
                            }
                public:     inline explicit releaser(petilil::event::subscription * subscription) : subscription(subscription) {}
                public:     releaser(void) = delete;
                public:     inline ~releaser(void) override {
                                if (subscription != nullptr) {
                                    delete subscription;
                                    subscription = nullptr;
                                }
                            }
                public:     releaser(const petilil::event::subscription::releaser & o) = delete;
                public:     releaser(petilil::event::subscription::releaser && o) noexcept = delete;
                public:     petilil::event::subscription::releaser & operator=(const petilil::event::subscription::releaser & o) = delete;
                public:     petilil::event::subscription::releaser & operator=(petilil::event::subscription::releaser && o) noexcept = delete;
                };
    public:     using                                           collection = psyduck::linked::list<petilil::event::subscription, petilil::event::link>;
    protected:  petilil::event::generator *                     container;
    protected:  petilil::event::subscription *                  prev;
    protected:  petilil::event::subscription *                  next;
    protected:  petilil::event::link *                          head;
    protected:  petilil::event::link *                          tail;
    protected:  pokemon::faint *                                exception;
    protected:  unsigned long                                   size;
    protected:  unsigned int                                    properties;
    protected:  unsigned int                                    status;
    protected:  petilil::event::subscription::callback::set     subscriptionSet;
    public:     inline bool cancel(void) override;
    protected:  virtual void raise(petilil::event::link * o, pokemon::faint * e) = 0;
    protected:  virtual void subscriptionOn(unsigned int type, pokemon::faint * e = nullptr) = 0;
    protected:  virtual int processOn(petilil::event::link * o) noexcept = 0;
    public:     inline const pokemon::faint * faintGet(void) const;
    public:     inline unsigned long eventCnt(void) const;
    public:     inline unsigned int stateChk(unsigned int state) const;
    public:     inline unsigned int propertyChk(unsigned int property) const;
    public:     inline virtual bool completeChk(void) const;
    public:     inline virtual bool cancelChk(void) const;
    public:     inline virtual bool finishChk(void) const;
    protected:  virtual petilil::event::link * add(petilil::event::link * o);
    protected:  virtual petilil::event::link * del(petilil::event::link * o);
    protected:  virtual void clear(void);
    protected:  inline explicit subscription(unsigned int properties);
    protected:  inline subscription(unsigned int properties, petilil::event::subscription::callback::function on);
    protected:  inline subscription(unsigned int properties, petilil::event::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(unsigned int properties, petilil::event::subscription::callback::function on, petilil::event::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(void);
    protected:  inline ~subscription(void) override;
    public:     subscription(const petilil::event::subscription & o) = delete;
    public:     subscription(petilil::event::subscription && o) noexcept = delete;
    public:     petilil::event::subscription & operator=(const petilil::event::subscription & o) = delete;
    public:     petilil::event::subscription & operator=(petilil::event::subscription && o) noexcept = delete;
    public:     friend petilil::event::subscription::collection;
    public:     friend psyduck::linked::list<petilil::event::generator, petilil::event::subscription>;
    public:     friend petilil::event::link;
    public:     friend petilil::event::generator;
    };

    class petilil::event::modifiable::subscription : public virtual petilil::event::subscription {
    protected:  void subscriptionOn(unsigned int type, pokemon::faint * e = nullptr) override;
    protected:  inline explicit subscription(unsigned int properties);
    protected:  inline subscription(unsigned int properties, petilil::event::subscription::callback::function on);
    protected:  inline subscription(unsigned int properties, petilil::event::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(unsigned int properties, petilil::event::subscription::callback::function on, petilil::event::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(void);
    protected:  inline ~subscription(void) override;
    public:     subscription(const petilil::event::modifiable::subscription & o) = delete;
    public:     subscription(petilil::event::modifiable::subscription && o) noexcept = delete;
    public:     petilil::event::modifiable::subscription & operator=(const petilil::event::modifiable::subscription & o) = delete;
    public:     petilil::event::modifiable::subscription & operator=(petilil::event::modifiable::subscription && o) noexcept = delete;
    };

    class petilil::event::generator : public sync {
    protected:  inline static petilil::event::subscription * subscriptionRel(petilil::event::subscription * o);
    public:     using                           collection = psyduck::linked::list<petilil::event::generator, petilil::event::subscription>;
    protected:  unsigned long                   size;
    protected:  petilil::event::subscription *  head;
    protected:  petilil::event::subscription *  tail;
    protected:  petilil::event::engine *        engine;
    protected:  runnable::queue                 queue;
    public:     virtual petilil::event::subscription * add(petilil::event::subscription * o);
    public:     virtual petilil::event::subscription * del(petilil::event::subscription * o);
    public:     void clear(void);
    public:     inline virtual unsigned long on(unsigned long n = declaration::infinite);
    protected:  inline explicit generator(petilil::event::engine * engine);
    protected:  inline generator(void);
    protected:  inline ~generator(void) override;
    public:     generator(const petilil::event::generator & o) = delete;
    public:     generator(petilil::event::generator && o) noexcept = delete;
    public:     petilil::event::generator & operator=(const petilil::event::generator & o) = delete;
    public:     petilil::event::generator & operator=(petilil::event::generator && o) noexcept = delete;
    public:     friend petilil::event::generator::collection;
    };

    struct petilil::commandable {
    public:     class link;
    public:     class event;
    public:     class envelope;
    public:     struct callback;
    public:     class subscription;
    public:     class generator;
    public:     class processor;
    public:     struct modifiable;
    };

    class petilil::commandable::event : public petilil::event {
    public:     constexpr static unsigned int execute   = 0;
    public:     constexpr static unsigned int max       = 1;
    public:     using link          = petilil::commandable::link;
    public:     using queue         = petilil::event::queue;
    public:     using engine        = petilil::event::engine;
    public:     using envelope      = petilil::commandable::envelope;
    public:     using callback      = petilil::commandable::callback;
    public:     using generator     = petilil::commandable::generator;
    public:     using processor     = petilil::commandable::processor;
    public:     using subscription  = petilil::commandable::subscription;
    public:     using modifiable    = petilil::commandable::modifiable;
    public:     inline event(unsigned int identifier, petilil::commandable::link * node);
    public:     inline event(void);
    public:     inline ~event(void) override;
    public:     event(const petilil::commandable::event & o) = delete;
    public:     event(petilil::commandable::event && o) noexcept = delete;
    public:     petilil::commandable::event & operator=(const petilil::commandable::event & o) = delete;
    public:     petilil::commandable::event & operator=(petilil::commandable::event && o) noexcept = delete;
    };

    struct petilil::commandable::callback : public petilil::event::callback {
    public:     struct set;
    public:     typedef void (*function)(pokemonism::commandable &, unsigned int, petilil::commandable::envelope &, const pokemon::faint *);
    public:     inline petilil::commandable::callback::function get(void) const { return reinterpret_cast<petilil::commandable::callback::function>(func); }
    public:     callback(void) {}
    public:     explicit callback(petilil::commandable::callback::function f) : petilil::event::callback(reinterpret_cast<petilil::event::callback::function>(f)) {}
    };

    struct petilil::commandable::callback::set {
    public:     petilil::commandable::callback::function functions[petilil::commandable::event::max];
    public:     set(void) { functions[petilil::commandable::event::execute] = nullptr; }
    public:     explicit set(petilil::commandable::callback::function execute) { functions[petilil::commandable::event::execute] = execute; }
    };

    struct petilil::commandable::modifiable {
    public:     class subscription;
    };

    class petilil::commandable::subscription : public virtual petilil::event::subscription {
    public:     using property = petilil::event::subscription::property;
    public:     using state = petilil::event::subscription::state;
    public:     struct callback : public petilil::event::subscription::callback {
                public:     typedef void (*function)(const petilil::commandable::subscription &, unsigned int, const pokemon::faint * e);
                public:     typedef void (*modifier)(const petilil::commandable::modifiable::subscription &, unsigned int, const pokemon::faint * e);
                public:     struct set {
                            public:     petilil::commandable::subscription::callback::function on;
                            public:     petilil::commandable::subscription::callback::modifier rel;
                            public:     inline set(void) : on(nullptr), rel(nullptr) {}
                            public:     inline explicit set(petilil::commandable::subscription::callback::function on) : on(on), rel(nullptr) {}
                            public:     inline explicit set(petilil::commandable::subscription::callback::modifier rel) : on(nullptr), rel(rel) {}
                            public:     inline set(petilil::commandable::subscription::callback::function on, petilil::commandable::subscription::callback::modifier rel) : on(on), rel(rel) {}
                            public:     inline ~set(void) {
                                            on = nullptr;
                                            rel = nullptr;
                                        }
                            };
                };
    public:     using releaser = petilil::event::subscription::releaser;
    public:     using command = commandable;
    protected:  int count;
    protected:  pokemonism::commandable * object;
    protected:  petilil::commandable::callback::set callbackSet;
    public:     inline virtual void callbackOn(petilil::commandable::link * o, unsigned int type, pokemon::faint * e = nullptr);
    public:     inline virtual const pokemonism::commandable * objectGet(void) const;
    protected:  inline virtual pokemonism::commandable * objectGet(void);
    public:     inline int executeCnt(void) const;
    public:     inline virtual void executeSet(void);
    protected:  inline void raise(petilil::event::link * o, pokemon::faint * e) override;
    protected:  int processOn(petilil::event::link * o) noexcept override;
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::function on);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::function on, petilil::commandable::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(void);
    protected:  inline ~subscription(void) override;
    public:     subscription(const petilil::commandable::subscription & o) = delete;
    public:     subscription(petilil::commandable::subscription && o) noexcept = delete;
    public:     petilil::commandable::subscription & operator=(const petilil::commandable::subscription & o) = delete;
    public:     petilil::commandable::subscription & operator=(petilil::commandable::subscription && o) noexcept = delete;
    public:     friend petilil::commandable::processor;
    };

    class petilil::commandable::modifiable::subscription : public virtual petilil::commandable::subscription, public petilil::event::modifiable::subscription {
    public:     using property = petilil::commandable::subscription::property;
    public:     using state = petilil::commandable::subscription::state;
    public:     using callback = petilil::commandable::subscription::callback;
    public:     using releaser = petilil::event::subscription::releaser;
    public:     using command = commandable;
    public:     inline virtual pokemonism::commandable * objectPop(void);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(void);
    protected:  inline ~subscription(void) override;
    public:     subscription(const petilil::commandable::modifiable::subscription & o) = delete;
    public:     subscription(petilil::commandable::modifiable::subscription && o) noexcept = delete;
    public:     petilil::commandable::modifiable::subscription & operator=(const petilil::commandable::modifiable::subscription & o) = delete;
    public:     petilil::commandable::modifiable::subscription & operator=(petilil::commandable::modifiable::subscription && o) noexcept = delete;
    public:     friend petilil::commandable::generator;
    };

    class petilil::commandable::envelope : public virtual petilil::event::envelope {
    protected:  primitivable * output;
    public:     inline petilil::commandable::subscription * subscriptionGet(void) const override {
                    return pokemon::cast<petilil::commandable::subscription *>(container);
                }
    public:     inline explicit envelope(petilil::commandable::subscription * subscription, int ret) : petilil::event::envelope(subscription, ret), output(nullptr) {}
    public:     inline envelope(petilil::commandable::subscription * subscription, int ret, pokemon::faint * exception) : petilil::event::envelope(subscription, ret, exception), output(nullptr) {}
    public:     inline envelope(void) : output(nullptr) {}
    public:     inline ~envelope(void) override {
                    pokemon_training_exit_check(output != nullptr, return);
                }
    public:     envelope(const petilil::commandable::envelope & o) = delete;
    public:     envelope(petilil::commandable::envelope && o) noexcept = delete;
    public:     petilil::commandable::envelope & operator=(const petilil::commandable::envelope & o) = delete;
    public:     petilil::commandable::envelope & operator=(petilil::commandable::envelope && o) noexcept = delete;
    };

    class petilil::commandable::link : public petilil::event::link, public virtual commandable::envelope {
    public:     inline void outputSet(primitivable * o) { output = o; }
    public:     inline explicit link(petilil::commandable::subscription * subscription) : petilil::event::link(subscription) {}
    public:     inline link(void) {}
    public:     inline ~link(void) override {}
    public:     link(const petilil::commandable::link & o) = delete;
    public:     link(petilil::commandable::link && o) noexcept = delete;
    public:     petilil::commandable::link & operator=(const petilil::commandable::link & o) = delete;
    public:     petilil::commandable::link & operator=(petilil::commandable::link && o) noexcept = delete;
    };

    class petilil::commandable::generator : public petilil::event::generator {
    public:     inline petilil::commandable::subscription * reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet);
    public:     inline petilil::commandable::subscription * reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on);
    public:     inline petilil::commandable::subscription * reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn);
    public:     inline petilil::commandable::subscription * reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn);
    protected:  inline explicit generator(petilil::event::engine * engine);
    protected:  inline generator(void);
    protected:  inline ~generator(void) override;
    public:     generator(const petilil::commandable::generator & o) = delete;
    public:     generator(petilil::commandable::generator && o) noexcept = delete;
    public:     petilil::commandable::generator & operator=(const petilil::commandable::generator & o) = delete;
    public:     petilil::commandable::generator & operator=(petilil::commandable::generator && o) noexcept = delete;
    public:     friend petilil::commandable::generator::collection;
    };

    class petilil::commandable::processor : public petilil::event::processor {
    public:     static int on(petilil::commandable::subscription & o, unsigned int type, petilil::commandable::link & node);
    public:     processor(void) {}
    public:     ~processor(void) override {}
    public:     processor(const petilil::commandable::processor & o) = delete;
    public:     processor(petilil::commandable::processor && o) noexcept = delete;
    public:     petilil::commandable::processor & operator=(const petilil::commandable::processor & o) = delete;
    public:     petilil::commandable::processor & operator=(petilil::commandable::processor && o) noexcept = delete;
    };

    struct petilil::command {
    public:     template <class objectable = commandable, typename outputable = primitivable> class link;
    public:     template <class objectable = commandable, typename outputable = primitivable> class event;
    public:     template <class objectable = commandable, typename outputable = primitivable> class envelope;
    public:     template <class objectable = commandable, typename outputable = primitivable> struct callback;
    public:     template <class objectable = commandable, typename outputable = primitivable> class subscription;
    public:     struct modifiable;
    };

    template <class objectable, typename outputable>
    class petilil::command::event : public petilil::commandable::event {
    public:     constexpr static unsigned int execute   = 0;
    public:     constexpr static unsigned int max       = 1;
    public:     using link          = petilil::command::link<objectable, outputable>;
    public:     using queue         = petilil::event::queue;
    public:     using engine        = petilil::event::engine;
    public:     using envelope      = petilil::command::envelope<objectable, outputable>;
    public:     using callback      = petilil::command::callback<objectable, outputable>;
    public:     using generator     = petilil::commandable::generator;
    public:     using processor     = petilil::commandable::processor;
    public:     using subscription  = petilil::command::subscription<objectable, outputable>;
    public:     using modifiable    = petilil::command::modifiable;
    public:     inline event(unsigned int identifier, petilil::command::link<objectable, outputable> * node) : petilil::commandable::event(identifier, node) {}
    public:     inline event(void) {}
    public:     inline ~event(void) override {}
    public:     event(const petilil::command::event<objectable, outputable> & o) = delete;
    public:     event(petilil::command::event<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::event<objectable, outputable> & operator=(const petilil::command::event<objectable, outputable> & o) = delete;
    public:     petilil::command::event<objectable, outputable> & operator=(petilil::command::event<objectable, outputable> && o) noexcept = delete;
    };

    struct petilil::command::modifiable {
    public:     template <class objectable = commandable, typename outputable = primitivable> class subscription;
    };

    template <class objectable, typename outputable>
    class petilil::command::subscription : public virtual petilil::commandable::subscription {
    public:     using property = petilil::commandable::subscription::property;
    public:     using state = petilil::commandable::subscription::state;
    public:     struct callback : public petilil::commandable::subscription::callback {
                public:     typedef void (*function)(const petilil::command::subscription<objectable, outputable> &, unsigned int, const pokemon::faint * e);
                public:     typedef void (*modifier)(const petilil::command::modifiable::subscription<objectable, outputable> &, unsigned int, const pokemon::faint * e);
                public:     struct set {
                            public:     petilil::command::subscription<objectable, outputable>::callback::function on;
                            public:     petilil::command::subscription<objectable, outputable>::callback::modifier rel;
                            public:     inline set(void) : on(nullptr), rel(nullptr) {}
                            public:     inline explicit set(petilil::command::subscription<objectable, outputable>::callback::function on) : on(on), rel(nullptr) {}
                            public:     inline explicit set(petilil::command::subscription<objectable, outputable>::callback::modifier rel) : on(nullptr), rel(rel) {}
                            public:     inline set(petilil::command::subscription<objectable, outputable>::callback::function on, petilil::command::subscription<objectable, outputable>::callback::modifier rel) : on(on), rel(rel) {}
                            public:     inline ~set(void) {
                                            on = nullptr;
                                            rel = nullptr;
                                        }
                            };
                };
    public:     using releaser = petilil::commandable::subscription::releaser;
    public:     using command = objectable;
    protected:  inline explicit subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet) : petilil::commandable::subscription(object, properties, callbackSet) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::subscription<objectable, outputable>::callback::function on) : petilil::commandable::subscription(object, properties, callbackSet, on) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::subscription<objectable, outputable>::callback::modifier modifiableOn) : petilil::commandable::subscription(object, properties, callbackSet, modifiableOn) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::subscription<objectable, outputable>::callback::function on, petilil::command::subscription<objectable, outputable>::callback::modifier modifiableOn) : petilil::commandable::subscription(object, properties, callbackSet, on, modifiableOn) {}
    protected:  inline subscription(void) {}
    protected:  inline ~subscription(void) override {}
    public:     subscription(const petilil::command::subscription<objectable, outputable> & o) = delete;
    public:     subscription(petilil::command::subscription<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::subscription<objectable, outputable> & operator=(const petilil::command::subscription<objectable, outputable> & o) = delete;
    public:     petilil::command::subscription<objectable, outputable> & operator=(petilil::command::subscription<objectable, outputable> && o) noexcept = delete;
    };

    template <class objectable, typename outputable>
    class petilil::command::modifiable::subscription : public petilil::command::subscription<objectable, outputable>, public petilil::commandable::modifiable::subscription {
    public:     using property = petilil::command::subscription<objectable, outputable>::property;
    public:     using state = petilil::command::subscription<objectable, outputable>::state;
    public:     using callback = petilil::command::subscription<objectable, outputable>::callback;
    public:     using releaser = petilil::command::subscription<objectable, outputable>::releaser;
    public:     using command = objectable;
    public:     inline objectable * objectPop(void) override { return pokemon::cast<objectable *>(object); }
    protected:  inline explicit subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet) : petilil::command::subscription<objectable, outputable>(object, properties, callbackSet) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::modifiable::subscription<objectable, outputable>::callback::function on) : petilil::command::subscription<objectable, outputable>(object, properties, callbackSet, on) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::modifiable::subscription<objectable, outputable>::callback::modifier modifiableOn) : petilil::command::subscription<objectable, outputable>(object, properties, callbackSet, modifiableOn) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::modifiable::subscription<objectable, outputable>::callback::function on, petilil::command::modifiable::subscription<objectable, outputable>::callback::modifier modifiableOn) : petilil::command::subscription<objectable, outputable>(object, properties, callbackSet, on, modifiableOn) {}
    protected:  inline subscription(void) {}
    protected:  inline ~subscription(void) override {}
    public:     subscription(const petilil::command::modifiable::subscription<objectable, outputable> & o) = delete;
    public:     subscription(petilil::command::modifiable::subscription<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::modifiable::subscription<objectable, outputable> & operator=(const petilil::command::modifiable::subscription<objectable, outputable> & o) = delete;
    public:     petilil::command::modifiable::subscription<objectable, outputable> & operator=(petilil::command::modifiable::subscription<objectable, outputable> && o) noexcept = delete;
    };

    template <class objectable, typename outputable>
    class petilil::command::envelope : public pokemonism::generic::envelope<outputable>, public virtual petilil::event::envelope {
    public:     inline petilil::command::subscription<objectable, outputable> * subscriptionGet(void) const override { return pokemon::cast<petilil::command::subscription<objectable, outputable> *>(container); }
    public:     inline explicit envelope(petilil::command::subscription<objectable, outputable> * subscription) : petilil::event::envelope(subscription) {}
    public:     inline envelope(petilil::command::subscription<objectable, outputable> * subscription, pokemon::faint * exception) : petilil::event::envelope(subscription, exception) {}
    public:     inline envelope(void) {}
    public:     inline ~envelope(void) override {}
    public:     envelope(const petilil::command::envelope<objectable, outputable> & o) = delete;
    public:     envelope(petilil::command::envelope<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::envelope<objectable, outputable> & operator=(const petilil::command::envelope<objectable, outputable> & o) = delete;
    public:     petilil::command::envelope<objectable, outputable> & operator=(petilil::command::envelope<objectable, outputable> && o) noexcept = delete;
    };

    template <class objectable, typename outputable>
    class petilil::command::link : public petilil::event::link, public command::envelope<objectable, outputable> {
    public:     inline explicit link(petilil::command::subscription<objectable, outputable> * subscription) : petilil::event::link(subscription) {}
    public:     inline link(void) {}
    public:     inline ~link(void) override {}
    public:     link(const petilil::command::link<objectable, outputable> & o) = delete;
    public:     link(petilil::command::link<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::link<objectable, outputable> & operator=(const petilil::command::link<objectable, outputable> & o) = delete;
    public:     petilil::command::link<objectable, outputable> & operator=(petilil::command::link<objectable, outputable> && o) noexcept = delete;
    };

    template <class objectable, typename outputable>
    struct petilil::command::callback : public petilil::event::callback {
    public:     struct set;
    public:     typedef void (*function)(objectable &, unsigned int, petilil::command::envelope<outputable> &, pokemon::faint *);
    public:     inline petilil::command::callback<objectable, outputable>::function get(void) { return reinterpret_cast<petilil::command::callback<objectable, outputable>::function>(func); }
    public:     callback(void) {}
    public:     explicit callback(petilil::command::callback<objectable, outputable>::function f) : petilil::event::callback(reinterpret_cast<petilil::event::callback::function>(f)) {}
    };

    template <class objectable, typename outputable>
    struct petilil::command::callback<objectable, outputable>::set {
    public:     petilil::command::callback<objectable, outputable>::function functions[petilil::command::event<objectable, outputable>::max];
    public:     set(void) { functions[petilil::command::event<objectable, outputable>::execute] = nullptr; }
    public:     explicit set(petilil::command::callback<objectable, outputable>::function execute) { functions[petilil::command::event<objectable, outputable>::execute] = execute; }
    };

    class petilil::event::engine : public sync {
    public:     struct generator {
                public:     struct set {
                            public:     petilil::commandable::generator * generator;
                            };
                };
    protected:  petilil::event::queue * queue;
    public:     engine(void);
    public:     ~engine(void) override;
    public:     engine(const petilil::event::engine & o) = delete;
    public:     engine(petilil::event::engine && o) noexcept = delete;
    public:     petilil::event::engine & operator=(const petilil::event::engine & o) = delete;
    public:     petilil::event::engine & operator=(petilil::event::engine && o) noexcept = delete;
    };

    inline const char * petilil::name(void) const noexcept {
        return petilil::tag;
    }


    inline void petilil::recall(petilil::cleaner f) {
        pokemon_training_check(f == nullptr, f = pokemon::clean<petilil>);

        clean = f;
    }

    inline petilil::~petilil(void) {
        pokemon_training_exit_check(clean != nullptr, (void)(0));
    }



}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/petilil/event.hh>
#include <pokemonism/petilil/event/link.hh>
#include <pokemonism/petilil/event/queue.hh>
#include <pokemonism/petilil/event/envelope.hh>
#include <pokemonism/petilil/event/generator.hh>
#include <pokemonism/petilil/event/subscription.hh>
#include <pokemonism/petilil/event/subscription/callback/set.hh>
#include <pokemonism/petilil/event/modifiable/subscription.hh>

#include <pokemonism/petilil/commandable/event.hh>
#include <pokemonism/petilil/commandable/generator.hh>
#include <pokemonism/petilil/commandable/processor.hh>
#include <pokemonism/petilil/commandable/subscription.hh>
#include <pokemonism/petilil/commandable/modifiable/subscription.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_PETILIL_HH__