/**
 * @file        pokemonism/latios/general/node.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_GENERAL_NODE__HH__
#define   __POKEMONISM_LATIOS_GENERAL_NODE__HH__

#include <pokemonism/latios/external/subscription.hh>
#include <pokemonism/latios/general/event.hh>

namespace pokemonism {
    namespace latios {
        namespace general {

            class subscription;

            class node {
            public:     virtual int emit(exception * e) = 0;
            public:     virtual int emit(void) = 0;
            public:     virtual int complete(void) = 0;
            public:     virtual void cancel(void) = 0;

                // message
                // output, status, result
                // channel
                // observe event parameter ...
                // content
                // observe progress
                // observe(result), observe(response), observe(output)

            public:     node(void) {}
            public:     virtual ~node(void) {}
            public:     node(const node & o) = delete;
            public:     node(node && o) noexcept = delete;
            public:     node & operator=(const node & o) = delete;
            public:     node & operator=(node && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_GENERAL_NODE__HH__
