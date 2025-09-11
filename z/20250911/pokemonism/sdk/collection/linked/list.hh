/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_COLLECTION_LINKED_LIST_HH__
#define   __POKEMONISM_SDK_COLLECTION_LINKED_LIST_HH__

#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/sdk/collection/sequenceable.hh>

namespace pokemonism::sdk::collection::linked {

    template <typename element>
    class list : public sequenceable<element> {
    protected:  class node {
                protected:  list<element> * container;
                protected:  node * prev;
                protected:  node * next;
                protected:  element value;
                public:     explicit node(const element & value);
                public:     explicit node(element && value);
                public:     node(void);
                public:     virtual ~node(void);
                public:     node(const node & o) = delete;
                public:     node(node && o) noexcept = delete;
                public:     node & operator=(const node & o) = delete;
                public:     node & operator=(node && o) noexcept = delete;
                public:     friend pokemonism::sdk::linked::list<list<element>, list<element>::node>;
                public:     friend list<element>;
                };
    public:     using collection = pokemonism::sdk::linked::list<list<element>, list<element>::node>;
    protected:  unsigned long size;
    protected:  list<element>::node * head;
    protected:  list<element>::node * tail;
    public:     inline element * add(const element & item) override;
    public:     inline element * add(element && item) override;
    public:     inline element & del(element & item) override;
    public:     inline const element & at(unsigned long index) const override;
    public:     inline element & at(unsigned long index) override;
    public:     inline const element & operator[](unsigned long index) const override;
    public:     inline element & operator[](unsigned long index) override;
    public:     inline unsigned long sizeGet(void) const override;
    public:     inline unsigned long capacityGet(void) const override;
    public:     inline void clear(void) override;
    public:     inline void clean(void) override;
    public:     inline void reset(void) override;
    public:     list(void);
    public:     ~list(void) override;
    public:     list(const list<element> & o);
    public:     list(list<element> && o) noexcept;
    public:     list<element> & operator=(const list<element> & o);
    public:     list<element> & operator=(list<element> && o) noexcept;
    public:     friend collection;
    };

    template <typename element>
    element * list<element>::add(const element & item) {
        collection::add(this, new list<element>::node(item), *this);

        return nullptr;
    }

    template <typename element>
    element * list<element>::add(element && item) {
        collection::add(this, new list<element>::node(std::move(item)), *this);

        return nullptr;
    }

    template <typename element>
    element & list<element>::del(element & item) {
        this->lock();
        for (list<element>::node * node = head; node != nullptr; node = node->next) {
            if (item == node->value) {
                allocator::del(collection::del(this, node));
                this->unlock();
                return item;
            }
        }
        this->unlock();
        return item;
    }

    template <typename element>
    const element & list<element>::at(unsigned long index) const {
        pokemon_develop_check(size <= index, exit(0));

        list<element>::node * node = head;

        for (unsigned long i = 0; i <= index; i = i + 1) node = node->next;

        return node->value;
    }

    template <typename element>
    element & list<element>::at(unsigned long index) {
        pokemon_develop_check(size <= index, exit(0));

        list<element>::node * node = head;

        for (unsigned long i = 0; i <= index; i = i + 1) node = node->next;

        return node->value;
    }

    template <typename element>
    const element & list<element>::operator[](unsigned long index) const {
        pokemon_develop_check(size <= index, exit(0));

        list<element>::node * node = head;

        for (unsigned long i = 0; i <= index; i = i + 1) node = node->next;

        return node->value;
    }

    template <typename element>
    element & list<element>::operator[](unsigned long index) {
        pokemon_develop_check(size <= index, exit(0));

        list<element>::node * node = head;

        for (unsigned long i = 0; i <= index; i = i + 1) node = node->next;

        return node->value;
    }

    template <typename element>
    inline unsigned long list<element>::sizeGet(void) const {
        return size;
    }

    template <typename element>
    inline unsigned long list<element>::capacityGet(void) const {
        return declaration::invalid;
    }

    template <typename element>
    inline void list<element>::clear(void) {
        collection::clear(this, *this);
    }

    template <typename element>
    inline void list<element>::clean(void) {
        collection::clear(this, *this);
    }

    template <typename element>
    inline void list<element>::reset(void) {
    }

    template <typename element>
    list<element>::list(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    template <typename element>
    list<element>::~list(void) {
        collection::clear(this, *this);
    }

    template <typename element>
    list<element>::list(const list<element> & o) : size(declaration::zero), head(nullptr), tail(nullptr) {
        for (list<element>::node * node = o.head; node != nullptr; node = node->next) {
            collection::add(this, new list<element>::node(node->value), *this);
        }
    }

    template <typename element>
    list<element>::list(list<element> && o) noexcept : size(o.size), head(o.head), tail(o.tail) {
        o.size = declaration::zero;
        o.head = nullptr;
        o.tail = nullptr;
    }

    template <typename element>
    list<element> & list<element>::operator=(const list<element> & o) {
        if (pointof(o) != this) {
            clear();

            for (list<element>::node * node = o.head; node != nullptr; node = node->next) {
                collection::add(this, new list<element>::node(node->value), *this);
            }
        }

        return *this;
    }

    template <typename element>
    list<element> & list<element>::operator=(list<element> && o) noexcept {
        if (pointof(o) != this) {
            clear();

            size = o.size;
            head = o.head;
            tail = o.tail;

            o.size = declaration::zero;
            o.head = nullptr;
            o.tail = nullptr;
        }

        return *this;
    }

    template <typename element>
    list<element>::node::node(const element & value): container(nullptr), prev(nullptr), next(nullptr), value(value) {

    }

    template <typename element>
    list<element>::node::node(element && value) : container(nullptr), prev(nullptr), next(nullptr), value(std::move(value)) {

    }

    template <typename element>
    list<element>::node::node(void) : container(nullptr), prev(nullptr), next(nullptr), value() {

    }

    template <typename element>
    list<element>::node::~node(void) {
        if (container != nullptr) list<element>::collection::del(container, this, *container);
    }

}

#endif // __POKEMONISM_SDK_COLLECTION_LINKED_LIST_HH__
