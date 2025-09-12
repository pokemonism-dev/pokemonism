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

    template <typename Collection, typename Element>
    class LinkedList {
    public:     static Element * add(Collection * container, Element * node);
    public:     static Element * del(Collection * container, Element * node);
    public:     static Element * pop(Collection * container);
    public:     static void clear(Collection * container);
    public:     static void clear(Collection * container, Element * (*rel)(Element *));
    public:     inline LinkedList(void);
    public:     inline virtual ~LinkedList(void);
    public:     LinkedList(const LinkedList<Collection, Element> & o) = delete;
    public:     LinkedList(LinkedList<Collection, Element> && o) noexcept = delete;
    public:     LinkedList<Collection, Element> & operator=(const LinkedList<Collection, Element> & o) = delete;
    public:     LinkedList<Collection, Element> & operator=(LinkedList<Collection, Element> && o) noexcept = delete;
    };

    // ReSharper disable once CppDFAConstantFunctionResult
    template <class Collection, class Element>
    Element * LinkedList<Collection, Element>::add(Collection * container, Element * node) {
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

    template <class Collection, class Element>
    Element * LinkedList<Collection, Element>::del(Collection * container, Element * node) {
        pokemon_develop_check(container == nullptr || node == nullptr || node->container != container, return node);

        Element * prev = node->prev;
        Element * next = node->next;

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

    template <class Collection, class Element>
    Element * LinkedList<Collection, Element>::pop(Collection * container) {
        pokemon_develop_check(container == nullptr, return nullptr);

        Element * node = container->head;
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

    template <class Collection, class Element>
    void LinkedList<Collection, Element>::clear(Collection * container) {
        pokemon_develop_check(container == nullptr, return);

        while (Element * node = LinkedList<Collection, Element>::pop(container)) Allocator::del(node);
    }


    template <class Collection, class Element>
    void LinkedList<Collection, Element>::clear(Collection * container, Element * (*rel)(Element *)) {
        pokemon_develop_check(container == nullptr, return);

        while (Element * node = LinkedList<Collection, Element>::pop(container)) Allocator::del(rel(node));
    }

    template <typename container, typename Element>
    inline LinkedList<container, Element>::LinkedList(void) {

    }

    template <typename container, typename Element>
    inline LinkedList<container, Element>::~LinkedList(void) {

    }

}

#endif // __POKEMONISM_SDK_LINKED_LIST_HH__