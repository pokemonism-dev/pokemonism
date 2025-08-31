/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_LIST_HH__
#define   __POKEMONISM_LIST_HH__

#include <pokemonism/pokemon/allocator.hh>
#include <pokemonism/pokemon/exception.hh>
#include <pokemonism/pokemon/interface/synchronizable.hh>

namespace pokemonism {
    namespace psyduck {
        namespace linked {

            template <class collection, class element>
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
            public:     list(void) {}
            public:     ~list(void) {}
            public:     list(const list<collection, element> & o) = delete;
            public:     list(list<collection, element> && o) noexcept = delete;
            public:     list<collection, element> operator=(const list<collection, element> & o) = delete;
            public:     list<collection, element> operator=(list<collection, element> && o) noexcept = delete;
            };

            template <class collection, class element>
            element * list<collection, element>::add(collection * container, element * node) {
                if (container == nullptr || node == nullptr) throw pokemonism::exception();
                if (node->container != nullptr) throw pokemonism::exception();

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
                if (container == nullptr || node == nullptr) throw pokemonism::exception();
                if (node->container != nullptr) throw pokemonism::exception();

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
                if (container == nullptr || node == nullptr) throw pokemonism::exception();
                if (node->container != container) throw pokemonism::exception();

                element * prev = node->prev;
                element * next = node->next;

                if (prev) {
                    prev->next = next;
                    node->prev = nullptr;
                } else {
                    container->head = next;
                }

                if (next) {
                    next->prev = next;
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
                if (container == nullptr || node == nullptr) throw pokemonism::exception();
                if (node->container != container) throw pokemonism::exception();

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
                    next->prev = next;
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
                if (container == nullptr) throw pokemonism::exception();

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
                if (container == nullptr) throw pokemonism::exception();

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
                if (container == nullptr) throw pokemonism::exception();

                while (element * node = list<collection, element>::pop(container)) allocator::del(node);
            }

            template <class collection, class element>
            void list<collection, element>::clear(collection * container, synchronizable & sync) {
                if (container == nullptr) throw pokemonism::exception();

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
                if (container == nullptr) throw pokemonism::exception();

                while (element * node = list<collection, element>::pop(container)) allocator::del(rel(node));
            }

            template <class collection, class element>
            void list<collection, element>::clear(collection * container, element * (*rel)(element *), synchronizable & sync) {
                if (container == nullptr) throw pokemonism::exception();

                sync.lock();
                while (element * node = list<collection, element>::pop(container)) {
                    sync.unlock();
                    allocator::del(rel(node));
                    sync.lock();
                }
                sync.unlock();
            }

        }
    }
}

#endif // __POKEMONISM_LIST_HH__