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
#include <pokemonism/envelope.hh>
#include <pokemonism/subscription.hh>

#include <pokemonism/runnable.hh>
#include <pokemonism/callbackable.hh>

#include <pokemonism/pokemon.hh>
#include <pokemonism/psyduck.hh>

#include "petilil.hh"

namespace pokemonism {

    // ### TODO: IMPLEMENT THIS
    class petilil : public pokemon {
    public:     constexpr static const char * tag = "petilil";
    public:     typedef void (*cleaner)(petilil *);
    public:     class event;
    public:     static petilil * go(void);
    protected:  petilil::cleaner clean;
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

    class petilil::event : public pokemonism::event {
    public:     class link;
    public:     class queue;
    public:     class engine;           // ### TODO | DEFINE THIS
    public:     class envelope;
    public:     class generator;        // ### TODO | DEFINE THIS
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

    class petilil::event::envelope : public pokemonism::envelopeable {
    protected:  petilil::event::subscription *  container;
    protected:  pokemon::faint *                exception;
    public:     inline virtual petilil::event::subscription * subscriptionGet(void) const;
    public:     inline virtual const pokemon::faint * exceptionGet(void) const;
    public:     inline explicit envelope(petilil::event::subscription * subscription);
    public:     inline envelope(petilil::event::subscription * subscription, pokemon::faint * exception);
    public:     inline envelope(void);
    public:     inline ~envelope(void) override;
    public:     envelope(const petilil::event::envelope & o) = delete;
    public:     envelope(petilil::event::envelope && o) noexcept = delete;
    public:     petilil::event::envelope & operator=(const petilil::event::envelope & o) = delete;
    public:     petilil::event::envelope & operator=(petilil::event::envelope && o) noexcept = delete;
    };

    class petilil::event::link : public petilil::event::envelope {
    public:     static petilil::event::link * rem(petilil::event::link * o);
    protected:  petilil::event::link *          prev;
    protected:  petilil::event::link *          next;
    protected:  petilil::event *                event;
    public:     virtual void raise(pokemon::faint * e);
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
    public:     struct state {
                public:     struct type {
                            public:     constexpr static unsigned int gen = 0U;
                            public:     constexpr static unsigned int add = 1U;
                            public:     constexpr static unsigned int chk = 2U;
                            public:     constexpr static unsigned int del = 3U;
                            public:     constexpr static unsigned int rel = 4U;
                            public:     constexpr static unsigned int max = 5U;
                            };
                public:     constexpr static unsigned int gen       = (0x00000001U <<  0U);
                public:     constexpr static unsigned int add       = (0x00000001U <<  1U);
                public:     constexpr static unsigned int chk       = (0x00000001U <<  2U);
                public:     constexpr static unsigned int del       = (0x00000001U <<  3U);
                public:     constexpr static unsigned int rel       = (0x00000001U <<  4U);
                public:     constexpr static unsigned int cancel    = (0x00000001U <<  5U);
                public:     constexpr static unsigned int complete  = (0x00000001U <<  6U);
                public:     constexpr static unsigned int faint     = (0x00000001U <<  7U);
                public:     constexpr static unsigned int max       = (0x00000001U <<  8U);
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
    protected:  virtual pokemon::faint * raise(petilil::event::link * o, pokemon::faint * e) = 0;
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

    class petilil::event::modifiable::subscription : public petilil::event::subscription {
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
#include <pokemonism/petilil/event/subscription.hh>
#include <pokemonism/petilil/event/subscription/callback/set.hh>
#include <pokemonism/petilil/event/modifiable/subscription.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_PETILIL_HH__