/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "subscription.hh"

#include "event.hh"
#include "generator.hh"
#include "node.hh"

namespace pokemonism {
    namespace wattrel {

        subscription::~subscription(void) {
            clear();

            if (container != nullptr) container->del(this);
        }

        void subscription::add(wattrel::node * node) {
            if (node == nullptr || node->container != nullptr) throw pokemon::exception();

            collection::add(this, node);
        }

        void subscription::del(wattrel::node * node) {
            if (node == nullptr || node->container != this) throw pokemon::exception();

            collection::del(this, node);
        }

        void subscription::clear(void) {
            while (head != nullptr) del(head);
        }
    }
}
