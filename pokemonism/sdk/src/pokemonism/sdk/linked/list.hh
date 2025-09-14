/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_SDK_LINKED_LIST_HH__
#define   __POKEMONISM_SDK_LINKED_LIST_HH__

#include <pokemonism/sdk/exception.hh>
#include <pokemonism/sdk/allocator.hh>

namespace pokemonism::sdk {
    namespace linked {
        template <typename collection, typename element>
        class list {
        public:     static element * add(collection * container, element * node);
        public:     static element * del(collection * container, element * node);
        public:     static element * pop(collection * container);
        public:     static void clear(collection * container);
        public:     static void clear(collection * container, element * (*rel)(element *));
        public:     inline list(void);
        public:     inline virtual ~list(void);
        public:     list(const list<collection, element> & o) = delete;
        public:     list(list<collection, element> && o) noexcept = delete;
        public:     list<collection, element> & operator=(const list<collection, element> & o) = delete;
        public:     list<collection, element> & operator=(list<collection, element> && o) noexcept = delete;
        };

        // ReSharper disable once CppDFAConstantFunctionResult
        template <class collection, class element>
        element * list<collection, element>::add(collection * container, element * node) {
            pokemon_develop_check(container == nullptr || node == nullptr || node->container != nullptr, return node);

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
        element * list<collection, element>::del(collection * container, element * node) {
            pokemon_develop_check(container == nullptr || node == nullptr || node->container != container, return node);

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
        element * list<collection, element>::pop(collection * container) {
            pokemon_develop_check(container == nullptr, return nullptr);

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
        void list<collection, element>::clear(collection * container) {
            pokemon_develop_check(container == nullptr, return);

            while (element * node = list<collection, element>::pop(container)) allocator::del(node);
        }


        template <class collection, class element>
        void list<collection, element>::clear(collection * container, element * (*rel)(element *)) {
            pokemon_develop_check(container == nullptr, return);

            while (element * node = list<collection, element>::pop(container)) allocator::del(rel(node));
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