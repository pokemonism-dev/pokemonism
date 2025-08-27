/**
 * @file        pokemon/latios/linked/list.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_LINKED_LIST__HH__
#define   __POKEMONISM_POKEMON_LATIOS_LINKED_LIST__HH__

#include <pokemon/log.hh>
#include <pokemon/allocator.hh>

#include <pokemon/latios/linked.hh>

namespace pokemon { namespace latios { namespace linked {

    // ReSharper disable once CppClassCanBeFinal
    class list {
    public:     template <typename container_type, typename node_type> inline static void clear(container_type * container);
    public:     template <typename container_type, typename node_type> inline static void clear(container_type * container, node_type * (*destructor)(node_type *));
    public:     template <typename container_type, typename node_type> inline static node_type * add(container_type * container, node_type * node);
    public:     template <typename container_type, typename node_type> inline static node_type * del(container_type * container, node_type * node);
    public:     template <typename container_type, typename node_type> inline static node_type * pop(container_type * container);
    public:     template <typename container_type, typename node_type> inline static node_type * push(container_type * container, node_type * node);
    public:     list(void) {}
    public:     virtual ~list(void) {}
    public:     list(const list & o) = delete;
    public:     list(list && o) noexcept = delete;
    public:     list & operator=(const list & o) = delete;
    public:     list & operator=(list && o) noexcept = delete;
    };

    // ReSharper disable once CppDFAConstantFunctionResult
    template <typename container_type, typename node_type>
    node_type * list::add(container_type * container, node_type * node) {
        critical_quick_throw_check(container == nullptr || node == nullptr, exceptional::nullpointer, return node);
        critical_quick_throw_check(node->container != nullptr, exceptional::unclean::node, return node);

        diagnostic_quick_check(node->next != nullptr, node->next = nullptr);

        node->prev = container->tail;
        if (node->prev) {
            node->prev->next = node;
        } else {
            container->head = node;
        }
        node->container = container;
        container->tail = node;
        container->size = container->size + 1;
        return nullptr;
    }

    // ReSharper disable once CppDFAConstantFunctionResult
    template <typename container_type, typename node_type>
    node_type * list::push(container_type * container, node_type * node) {
        critical_quick_throw_check(container == nullptr || node == nullptr, exceptional::nullpointer, return node);
        critical_quick_throw_check(node->container != nullptr, exceptional::unclean::node, return node);

        diagnostic_quick_check(node->next != nullptr, node->next = nullptr);

        node->prev = container->tail;
        if (node->prev) {
            node->prev->next = node;
        } else {
            container->head = node;
        }
        node->container = container;
        container->tail = node;
        container->size = container->size + 1;
        return nullptr;
    }

    template <typename container_type, typename node_type>
    node_type * list::del(container_type * container, node_type * node) {
        critical_quick_throw_check(node == nullptr, exceptional::nullpointer, return node);
        develop_quick_throw_check(node->container == nullptr, exceptional::nullpointer, return node);
        develop_quick_throw_check(container == nullptr, exceptional::nullpointer, return node);
        critical_quick_throw_check(container != node->container, exceptional::unmatched::container, container = node->container);
        critical_quick_throw_check(container->size == 0, exceptional::critical, exit(0));

        node_type * prev = node->prev;
        node_type * next = node->next;

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

    template <typename container_type, typename node_type>
    node_type * list::pop(container_type * container) {
        critical_quick_throw_check(container == nullptr, exceptional::nullpointer, return nullptr);
        critical_quick_throw_check(container->size == 0 && container->head != nullptr, exceptional::critical, exit(0));

        node_type * node = container->head;
        if (node) {
            node_type * next = node->next;
            if (next) {
                next->prev = nullptr;
            } else {
                container->tail = nullptr;
            }
            container->head = next;
            container->size = container->size - 1;
            node->container = nullptr;
        }

        return node;
    }

    template <typename container_type, typename node_type>
    void list::clear(container_type * container) {
        critical_quick_throw_check(container == nullptr, exceptional::nullpointer, return);

        node_type * node = nullptr;
        while ((node = list::pop<container_type, node_type>(container)) != nullptr) allocator::del<node_type>(node);
    }

    template <typename container_type, typename node_type>
    void list::clear(container_type * container, node_type * (*destructor)(node_type *)) {
        critical_quick_throw_check(container == nullptr || destructor == nullptr, exceptional::nullpointer, return);

        node_type * node = nullptr;
        while ((node = list::pop<container_type, node_type>(container)) != nullptr) allocator::del<node_type>(destructor(node));
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_LINKED_LIST__HH__