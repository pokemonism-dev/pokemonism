/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */


#include "stream.hh"

namespace pokemonism::sdk {

    unsigned long stream::pageGet(void) const { return container != nullptr ? container->pageGet() : stream::buffer::defaultPage; }

    stream::stream(stream::buffer * container) : container(nullptr), prev(nullptr), next(nullptr) {
        pokemon_develop_check(container == nullptr, return);

        container->add(this);
    }

    stream::~stream(void) {
        if (container != nullptr) container->del(this);
    }

    stream * stream::buffer::add(stream * node) {
        pokemon_develop_check(node == nullptr || node->container != nullptr, return node);

        collection::add(this, node);

        return nullptr;
    }

    stream * stream::buffer::del(stream * node) {
        pokemon_develop_check(node == nullptr || node->container != this, return node);

        collection::del(this, node);

        return node;
    }

    stream * stream::buffer::gen(void) {
        return new stream(this);
    }

    stream * stream::buffer::untilGet(unsigned long n) {
        trash();

        if (head == nullptr) return nullptr;

        if (head->lengthGet() == 0) return nullptr;

        stream * node = nullptr;

        while (head->lengthGet() < n && (node = head->next) != nullptr) {
            if (node->lengthGet() == 0) break;

            head->cat(std::move(*node));
            del(node);
        }

        return head;
    }

    stream * stream::buffer::streamGet(unsigned long n) {
        shrink();

        if (tail == nullptr || (tail->capacity >= stream::buffer::page && tail->remainGet() < n)) gen();

        if (tail != nullptr) tail->grow(n);

        return tail;
    }

    void stream::buffer::trash(void) {
        while (head != nullptr && head->lengthGet() == 0) {
            if (head->next != nullptr) {
                del(head);
                continue;
            }
            head->fit();
            break;
        }
    }

    void stream::buffer::shrink(void) {
        while (tail != nullptr && tail->lengthGet() == 0 && tail->remainGet() > 0) {
            if (const stream * node = tail->prev; node != nullptr && node->capacityGet() < stream::buffer::page) {
                del(tail);
                continue;
            }
            break;
        }
    }

    void stream::buffer::fit(void) {
        trash();
        shrink();
    }

    void stream::buffer::clear(void) {
        collection::clear(this);
    }

    void stream::buffer::clean(void) {
        // ### 20250909: UPDATE THIS
        collection::clear(this);
    }

    void stream::buffer::reset(void) {
        // ### 20250909: UPDATE THIS
        collection::clear(this);
    }


}