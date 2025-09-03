/**
 * @file            pokemonism/ralts/kirlia/gardevoir/subscription.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_SUBSCRIPTION_HH__
#define   __POKEMONISM_GARDEVOIR_SUBSCRIPTION_HH__

#include <pokemonism/ralts/kirlia/subscription.hh>

#include <pokemonism/ralts/kirlia/gardevoir/generator.hh>

#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {
    namespace gardevoir {

        class node;

        class subscription : public virtual kirlia::subscription {
        public:     typedef psyduck::linked::list<gardevoir::subscription, gardevoir::node> collection;
        public:     struct function {
                    public:     class rel : public pokemon::runnable::queue::func {
                                protected:  gardevoir::subscription * subscription;
                                public:     void operator()(void) override { subscription = allocator::del(subscription); }
                                public:     explicit rel(gardevoir::subscription * subscription) : subscription(subscription) {}
                                public:     ~rel(void) override { subscription = allocator::del(subscription); }
                                public:     rel(const gardevoir::subscription::function::rel & o) = delete;
                                public:     rel(gardevoir::subscription::function::rel && o) noexcept = delete;
                                public:     gardevoir::subscription::function::rel & operator=(const gardevoir::subscription::function::rel & o) = delete;
                                public:     gardevoir::subscription::function::rel & operator=(gardevoir::subscription::function::rel && o) noexcept = delete;
                                };
                    };
        public:     struct state {
                    public:     constexpr static uint32 none        = (0x00000000U <<  0U);
                    public:     constexpr static uint32 gen         = (0x00000001U <<  0U);
                    public:     constexpr static uint32 reg         = (0x00000001U <<  1U);
                    public:     constexpr static uint32 exception   = (0x00000001U <<  2U);
                    public:     constexpr static uint32 complete    = (0x00000001U <<  3U);
                    public:     constexpr static uint32 cancel      = (0x00000001U <<  4U);
                    };
        protected:  gardevoir::generator * container;
        protected:  gardevoir::subscription * prev;
        protected:  gardevoir::subscription * next;
        protected:  uint64 size;
        protected:  gardevoir::node * head;
        protected:  gardevoir::node * tail;
        protected:  uint32 properties;
        protected:  uint32 status;
        protected:  kirlia::subscription::event::handler::set * subscriptionSet;
        public:     inline virtual void completeSet(void) { status = status | gardevoir::subscription::state::complete; }
        public:     inline virtual void cancelSet(void) { status = status | gardevoir::subscription::state::cancel; }
        public:     inline virtual void exceptionSet(void) { status = status | gardevoir::subscription::state::exception; }
        public:     inline virtual bool completeChk(void) const { return (status & gardevoir::subscription::state::complete) != declaration::none; }
        public:     inline virtual bool cancelChk(void) const { return (status & gardevoir::subscription::state::cancel) != declaration::none; }
        public:     inline virtual bool exceptionChk(void) const  { return (status & gardevoir::subscription::state::exception) != declaration::none; }
        public:     inline virtual bool finishChk(void) const { return (status & (gardevoir::subscription::state::complete | gardevoir::subscription::state::cancel | gardevoir::subscription::state::exception)) != declaration::none; }
        public:     bool cancel(void) override {
                        if (finishChk()) return false;

                        status = status | gardevoir::subscription::state::cancel;

                        clear();

                        if (container != nullptr) container->del(this);

                        return true;
                    }
        public:     inline virtual void on(uint32 type, pokemon::exception * e = nullptr) {
                        pokemon_develop_check(kirlia::subscription::event::type::max <= type, do {
                            allocator::del(e);
                            return;
                        } while (0));

                        if (e != nullptr) exceptionSet();

                        if (subscriptionSet != nullptr) {
                            if (const kirlia::subscription::event::handler::type func = reinterpret_cast<kirlia::subscription::event::handler::type>((*subscriptionSet)[type]); func != nullptr) {
                                func(*this, type, e);
                            }
                        }
                        allocator::del(e);
                    }
        public:     virtual inline uint32 check(uint32 state) { return (status & state); }
        public:     virtual void raise(gardevoir::node * node) = 0;
        public:     virtual int on(gardevoir::node * node) = 0;
        protected:  gardevoir::node * add(gardevoir::node * node);
        protected:  gardevoir::node * del(gardevoir::node * node);
        protected:  void clear(void);
        protected:  inline explicit subscription(uint32 properties) : container(nullptr), prev(nullptr), next(nullptr), size(declaration::zero), head(nullptr), tail(nullptr), properties(properties), status(declaration::none), subscriptionSet(nullptr) {
                    }
        protected:  inline subscription(uint32 properties, const kirlia::subscription::event::handler::set & handlerSet) : container(nullptr), prev(nullptr), next(nullptr), size(declaration::zero), head(nullptr), tail(nullptr), properties(properties), status(declaration::none), subscriptionSet(nullptr) {
                        subscriptionSet = static_cast<kirlia::subscription::event::handler::set *>(allocator::gen(sizeof(kirlia::subscription::event::handler::set) * kirlia::subscription::event::type::max));
                        memcpy(subscriptionSet, handlerSet, sizeof(kirlia::subscription::event::handler::set) * kirlia::subscription::event::type::max);
                    }
        public:     subscription(void) = delete;
        public:     inline ~subscription(void) override {

                    }
        public:     subscription(const gardevoir::subscription & o) = delete;
        public:     subscription(gardevoir::subscription && o) noexcept = delete;
        public:     gardevoir::subscription & operator=(const gardevoir::subscription & o) = delete;
        public:     gardevoir::subscription & operator=(gardevoir::subscription && o) noexcept = delete;
        public:     friend collection;
        public:     friend gardevoir::node;
        public:     friend gardevoir::generator;
        public:     friend psyduck::linked::list<gardevoir::generator, gardevoir::subscription>;
        };

    }
}

#endif // __POKEMONISM_GARDEVOIR_SUBSCRIPTION_HH__