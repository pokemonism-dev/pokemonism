/**
 * @file        pokemonism/latios/internal/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__

#include <pokemonism/latios/event.hh>

#include <pokemonism/latios/internal/event.hh>
#include <pokemonism/latios/internal/generator.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            template <class ownable, class generatable = internal::generator>
            class subscription {
            public:     typedef ownable         owner;
            public:     typedef generatable     generator;
            public:     class node;
            // public:     class event : public internal::event {
            //
            //             public:     event(void);
            //             public:     ~event(void) override;
            //             public:     event(const event<generator> & o) = delete;
            //             public:     event(event<generator> && o) noexcept = delete;
            //             public:     event<generator> & operator=(const event<generator> & o) = delete;
            //             public:     event<generator> & operator=(event<generator> && o) noexcept = delete;
            //
            //             };
            // public:     class node {
            //             protected:  subscription *                              container;
            //             protected:  node *                                      prev;
            //             protected:  node *                                      next;
            //             protected:  subscription<owner, generator>::event *     event;
            //             public:     node(void);
            //             public:     virtual ~node(void);
            //             public:     node(const node & o);
            //             public:     node(node && o) noexcept;
            //             public:     node & operator=(const node & o);
            //             public:     node & operator=(node && o) noexcept;
            //             };
            //
            //
            //
            //
            //
            // protected:  generator * container;
            // protected:  subscription * prev;
            // protected:  subscription * next;
            // protected:  uint64 size;
            // protected:  node * head;
            // protected:  node * tail;
            // protected:  subscription::owner object;
            // protected:  uint32 properties;
            // protected:  uint32 status;
            // protected:  void * userdata;
            // public:     subscription(void);
            // public:     virtual ~subscription(void);
            // public:     subscription(const subscription & o) = delete;
            // public:     subscription(subscription && o) noexcept = delete;
            // public:     subscription & operator=(const subscription & o) = delete;
            // public:     subscription & operator=(subscription && o) noexcept = delete;
            };
        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__
