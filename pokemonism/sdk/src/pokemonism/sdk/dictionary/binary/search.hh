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
    class search {
    public:     static item * begin(collection * container);
    public:     static item * next(collection * container, item * node);
    protected:  static void splice(collection * container, item * x, item * y);
    public:     static item * add(collection * container, item * node);
    public:     static item * del(collection * container, item * node);
    public:     search(void) {}
    public:     virtual ~search(void) {}
    public:     search(const search<collection, item, comparator> & o) = delete;
    public:     search(search<collection, item, comparator> && o) noexcept = delete;
    public:     search<collection, item, comparator> & operator=(const search<collection, item, comparator> & o) = delete;
    public:     search<collection, item, comparator> & operator=(search<collection, item, comparator> && o) noexcept = delete;
    };

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::begin(collection * container) {
        pokemon_develop_check(container == nullptr, return nullptr);

        item * node = container->root;

        if (node) while (node->left) node = node->left;

        return node;
    }

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::next(collection * container, item * node) {
        item * parent = nullptr;
        if (node != nullptr) {
            if (node->right != nullptr) {
                node = node->right;
                while (node->left) node = node->left;
            } else {
                do {
                    parent = node->parent;
                    if (parent) {
                        if (node==parent->left) {
                            node = parent;
                            break;
                        }
                    }
                    node = parent;
                } while (node);
            }
        }
        return node;
    }

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::add(collection * container, item * node) {
        item * current = container->root;
        if (current == nullptr) {
            container->root = node;
            container->size = container->size + 1;
            node->container = container;
            return current;
        }
        do {
            const int result = comparator(node->value, current->value);
            if (result == 0) break;
            if (result > 0) {
                if (current->right == nullptr) {
                    current->right = node;
                    container->size = container->size + 1;
                    node->parent = current;
                    node->container = container;
                    current = nullptr;
                    break;
                }
                current = current->right;
            } else {
                if (current->left == nullptr) {
                    current->left = node;
                    container->size = container->size + 1;
                    node->parent = current;
                    node->container = container;
                    current = nullptr;
                    break;
                }
                current = current->left;
            }
        } while (current);

        return current;
    }

    template <typename collection, typename item, class comparator>
    void search<collection, item, comparator>::splice(collection * container, item * x, item * y) {
        item * parent = x->parent;
        item * left = x->left;
        item * right = x->right;
        const int parentLeft = parent && parent->left == x;

        x->parent = y->parent;
        if (x->parent) {
            if (x->parent->left == y) {
                x->parent->left = x;
            } else {
                x->parent->right = x;
            }
        } else {
            container->root = x;
        }

        x->left = y->left;
        if (x->left != nullptr) x->left->parent = x;
        x->right = y->right;
        if (x->right != nullptr) x->right->parent = x;

        y->parent = parent;
        if (y->parent != nullptr) {
            if (parentLeft) {
                y->parent->left = y;
            } else {
                y->parent->right = y;
            }
        } else {
            container->root = y;
        }

        y->left = left;
        if (y->left) y->left->parent = y;
        y->right = right;
        if (y->right) y->right->parent = y;
    }

    template <typename collection, typename item, class comparator>
    item * search<collection, item, comparator>::del(collection * container, item * node) {
        item * current = node;
        if (current) {
            if (current->left && current->right) {
                item * successor = current->right;
                while (successor->left) successor = successor->left;
                splice(container, current, successor);
                if (current->right) {
                    if(current->parent->left == current) {
                        current->parent->left = current->right;
                    } else {
                        current->parent->right = current->right;
                    }
                    current->right->parent = current->parent;
                    current->right = nullptr;
                } else {
                    if(current->parent->left == current) {
                        current->parent->left = nullptr;
                    } else {
                        current->parent->right = nullptr;
                    }
                }
                current->parent = nullptr;
                current->container = nullptr;
                container->size = container->size - 1;
            } else if (current->left) {
                if (current->parent) {
                    if (current->parent->left == current) {
                        current->parent->left = current->left;
                    } else {
                        current->parent->right = current->left;
                    }
                    current->left->parent = current->parent;
                    current->parent = nullptr;
                } else {
                    container->root = current->left;
                    current->left->parent = nullptr;
                }
                current->left = nullptr;
                current->container = nullptr;
                container->size = container->size - 1;
            } else if (current->right) {
                if (current->parent) {
                    if (current->parent->left == current) {
                        current->parent->left = current->right;
                    } else {
                        current->parent->right = current->right;
                    }
                    current->right->parent = current->parent;
                    current->parent = nullptr;
                } else {
                    container->root = current->right;
                    current->right->parent = nullptr;
                }
                current->right = nullptr;
                current->container = nullptr;
                container->size = container->size - 1;
            } else {
                if (current->parent) {
                    if (current->parent->left == current) {
                        current->parent->left = nullptr;
                    } else {
                        current->parent->right = nullptr;
                    }
                    current->parent = nullptr;
                    container->size = container->size - 1;
                }
            }
            current->container = nullptr;
        }
        return current;
    }
}

#endif // __POKEMONISM_SDK_DICTIONARY_BINARY_SEARCH_HH__