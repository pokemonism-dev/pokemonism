/**
 * @file        pokemonism/latios/internal/metadata.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_TAG__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_TAG__HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace latios { namespace internal { namespace metadata {

        struct event;
        struct queue;
        struct node;
        struct generator;
        struct subscription;

        struct event {
            queue * container;
            event * prev;
            event * next;
            node * node;
        };

        struct subscription {
            static subscription * rel(subscription * o) { return o; }
            generator * container;
            subscription * prev;
            subscription * next;
            uint64 size;
            node * head;
            node * tail;
            void on(void);  // TODO: UPDATE REAL ...
        };

        struct node {
            subscription * container;
            node * prev;
            node * next;
            event * event;
        };

        struct generator {
            uint64 size;
            subscription * head;
            subscription * tail;
        };

    } } }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_TAG__HH__