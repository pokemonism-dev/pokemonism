/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 19, 2025
 */

#ifndef   __POKEMONISM_SDK_DICTIONARY_BINARY_SEARCH_HH__
#define   __POKEMONISM_SDK_DICTIONARY_BINARY_SEARCH_HH__

#include <pokemonism/sdk/exception.hh>

namespace pokemonism::sdk::dictionary::binary {

    template <typename collection, typename item, class comparator>
    // // 이 템플릿이 요구하는 타입들의 '계약서'를 완성했습니다.
    // // 이제 컴파일러가 "이 타입은 이런 멤버를 가져야 해!"라고 명확히 알려줄 겁니다.
    // requires requires(collection c, item i, comparator comp) {
    //     // collection 타입에 대한 계약
    //     { c.root } -> is::declaration<item*&>;
    //     { c.size } -> is::integer;
    //
    //     // item 타입에 대한 계약
    //     { i.container } -> is::declaration<collection*&>;
    //     { i.parent }    -> is::declaration<item*&>;
    //     { i.left }      -> is::declaration<item*&>;
    //     { i.right }     -> is::declaration<item*&>;
    //     i.value; // 'value' 멤버가 존재해야 함
    //
    //     // comparator 타입에 대한 계약
    //     { comp(i.value, i.value) } -> std::convertible_to<int>;
    // }
    class search {
    public:     static item * begin(collection * container);
    public:     static item * next(collection * container, item * node);
    public:     static item * add(collection * container, item * node);
    public:     static item * del(collection * container, item * node);

    protected:  static void transplant(collection * container, item * u, item * v);
    private:    static item * minimum(item* node);

    public:     search(void) = delete;
    public:     ~search(void) = delete;
    public:     search(const search<collection, item, comparator> & o) = delete;
    public:     search(search<collection, item, comparator> && o) noexcept = delete;
    public:     search<collection, item, comparator> & operator=(const search<collection, item, comparator> & o) = delete;
    public:     search<collection, item, comparator> & operator=(search<collection, item, comparator> && o) noexcept = delete;
    };

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::minimum(item* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::begin(collection * container) {
        pokemon_develop_check(container == nullptr, return nullptr);
        return minimum(container->root);
    }

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::next(collection * container, item * node) {
        if (node == nullptr) return nullptr;

        // 오른쪽 서브트리가 있다면, 그곳의 가장 작은 노드가 후계자입니다.
        if (node->right) {
            return minimum(node->right);
        }

        // 오른쪽 서브트리가 없다면, 부모를 따라 올라가다가
        // 처음으로 왼쪽 자식이 되는 순간의 부모가 후계자입니다.
        item* parent = node->parent;
        while (parent && node == parent->right) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::add(collection * container, item * node) {
        pokemon_develop_check(container == nullptr || node == nullptr, return node);

        item* parent = nullptr;
        item** current_ptr = &container->root;
        comparator comp;

        while (*current_ptr) {
            parent = *current_ptr;
            const int result = comp(node->value, parent->value);

            if (result == 0) {
                return parent; // 중복 노드 발견, 기존 노드 반환
            }
            if (result > 0) {
                current_ptr = &parent->right;
            } else {
                current_ptr = &parent->left;
            }
        }

        *current_ptr = node;
        node->parent = parent;
        node->container = container;
        container->size++;

        return nullptr; // 성공적으로 추가됨
    }

    template <typename collection, typename item, class comparator>
    void search<collection, item, comparator>::transplant(collection * container, item * u, item * v) {
        if (u->parent == nullptr) {
            container->root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v) {
            v->parent = u->parent;
        }
    }

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::del(collection * container, item * node) {
        pokemon_develop_check(container == nullptr || node == nullptr, return nullptr);

        if (node->left == nullptr) {
            transplant(container, node, node->right);
        } else if (node->right == nullptr) {
            transplant(container, node, node->left);
        } else {
            item* successor = minimum(node->right);
            if (successor->parent != node) {
                transplant(container, successor, successor->right);
                successor->right = node->right;
                successor->right->parent = successor;
            }
            transplant(container, node, successor);
            successor->left = node->left;
            successor->left->parent = successor;
        }

        container->size--;
        // 안전을 위해 분리된 노드의 포인터들을 정리합니다.
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;
        node->container = nullptr;

        return node;
    }
}

#endif // __POKEMONISM_SDK_DICTIONARY_BINARY_SEARCH_HH__