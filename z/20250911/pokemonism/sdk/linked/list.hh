/**
 * @file            pokemonism/sdk/linked/list.hh
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 4, 2025
 */

#ifndef   __POKEMONISM_SDK_LINKED_LIST_HH__
#define   __POKEMONISM_SDK_LINKED_LIST_HH__

#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/exception.hh>
#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk {

    namespace linked {

        template <typename collection, typename element>
        class list {
        public:     static element * add(collection * container, element * node);
        public:     static element * add(collection * container, element * node, synchronizable & sync);
        public:     static element * del(collection * container, element * node);
        public:     static element * del(collection * container, element * node, synchronizable & sync);
        public:     static element * pop(collection * container);
        public:     static element * pop(collection * container, synchronizable & sync);
        public:     static void clear(collection * container);
        public:     static void clear(collection * container, synchronizable & sync);
        public:     static void clear(collection * container, element * (*rel)(element *));
        public:     static void clear(collection * container, element * (*rel)(element *), synchronizable & sync);
        public:     inline list(void);
        public:     inline virtual ~list(void);
        public:     list(const linked::list<collection, element> & o) = delete;
        public:     list(linked::list<collection, element> && o) noexcept = delete;
        public:     linked::list<collection, element> & operator=(const linked::list<collection, element> & o) = delete;
        public:     linked::list<collection, element> & operator=(linked::list<collection, element> && o) noexcept = delete;
        };

        template <class collection, class element>
        element * list<collection, element>::add(collection * container, element * node) {
            if (container == nullptr || node == nullptr) throw pokemonism::sdk::exception();
            if (node->container != nullptr) throw pokemonism::sdk::exception();

            node->prev = container->tail;
            if (node->prev) {
                node->prev->next = node;
            } else {
                container->head = node;
            }
            container->tail = node;
            container->size = container->size + 1;
            node->container = container;

            return nullptr;
        }

        template <class collection, class element>
        element * list<collection, element>::add(collection * container, element * node, synchronizable & sync) {
            if (container == nullptr || node == nullptr) throw pokemonism::sdk::exception();
            if (node->container != nullptr) throw pokemonism::sdk::exception();

            sync.lock();
            node->prev = container->tail;
            if (node->prev) {
                node->prev->next = node;
            } else {
                container->head = node;
            }
            container->tail = node;
            container->size = container->size + 1;
            node->container = container;
            sync.unlock();

            return nullptr;
        }

        template <class collection, class element>
        element * list<collection, element>::del(collection * container, element * node) {
            if (container == nullptr || node == nullptr) throw pokemonism::sdk::exception();
            if (node->container != container) throw pokemonism::sdk::exception();

            element * prev = node->prev;
            element * next = node->next;

            if (prev) {
                prev->next = next;
                node->prev = nullptr;
            } else {
                container->head = next;
            }

            if (next) {
                next->prev = prev;
                node->next = nullptr;
            } else {
                container->tail = prev;
            }

            container->size = container->size - 1;
            node->container = nullptr;

            return node;
        }

        template <class collection, class element>
        element * list<collection, element>::del(collection * container, element * node, synchronizable & sync) {
            if (container == nullptr || node == nullptr) throw pokemonism::sdk::exception();
            if (node->container != container) throw pokemonism::sdk::exception();

            sync.lock();
            element * prev = node->prev;
            element * next = node->next;

            if (prev) {
                prev->next = next;
                node->prev = nullptr;
            } else {
                container->head = next;
            }

            if (next) {
                next->prev = prev;
                node->next = nullptr;
            } else {
                container->tail = prev;
            }
            container->size = container->size - 1;
            node->container = nullptr;
            sync.unlock();

            return node;
        }

        template <class collection, class element>
        element * list<collection, element>::pop(collection * container) {
            if (container == nullptr) throw pokemonism::sdk::exception();

            element * node = container->head;
            if (node != nullptr) {
                if (node->next) {
                    container->head = node->next;
                    node->next->prev = nullptr;
                    node->next = nullptr;
                } else {
                    container->head = nullptr;
                    container->tail = nullptr;
                }
                container->size = container->size - 1;
                node->container = nullptr;
            }

            return node;
        }

        template <class collection, class element>
        element * list<collection, element>::pop(collection * container, synchronizable & sync) {
            if (container == nullptr) throw pokemonism::sdk::exception();

            sync.lock();
            element * node = container->head;
            if (node != nullptr) {
                if (node->next) {
                    container->head = node->next;
                    node->next->prev = nullptr;
                    node->next = nullptr;
                } else {
                    container->head = nullptr;
                    container->tail = nullptr;
                }
                container->size = container->size - 1;
                node->container = nullptr;
            }
            sync.unlock();

            return node;
        }

        template <class collection, class element>
        void list<collection, element>::clear(collection * container) {
            if (container == nullptr) throw pokemonism::sdk::exception();

            while (element * node = list<collection, element>::pop(container)) allocator::del(node);
        }

        template <class collection, class element>
        void list<collection, element>::clear(collection * container, synchronizable & sync) {
            if (container == nullptr) throw pokemonism::sdk::exception();

            sync.lock();
            while (element * node = list<collection, element>::pop(container)) {
                sync.unlock();
                allocator::del(node);
                sync.lock();
            }
            sync.unlock();
        }

        template <class collection, class element>
        void list<collection, element>::clear(collection * container, element * (*rel)(element *)) {
            if (container == nullptr) throw pokemonism::sdk::exception();

            while (element * node = list<collection, element>::pop(container)) allocator::del(rel(node));
        }

        template <class collection, class element>
        void list<collection, element>::clear(collection * container, element * (*rel)(element *), synchronizable & sync) {
            if (container == nullptr) throw pokemonism::sdk::exception();

            sync.lock();
            while (element * node = list<collection, element>::pop(container)) {
                sync.unlock();
                allocator::del(rel(node));
                sync.lock();
            }
            sync.unlock();
        }

        template <typename container, typename element>
        inline list<container, element>::list(void) {

        }

        template <typename container, typename element>
        inline list<container, element>::~list(void) {

        }

    }
}

#endif // __POKEMONISM_SDK_LINKED_LIST_HH__