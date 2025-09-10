/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "buffer.hh"

namespace pokemonism::sdk {

    stream * stream::buffer::add(stream * node) {
        pokemon_develop_check(node == nullptr || node->container != nullptr, return node);

        collection::add(this, node);

        if (prepare == nullptr) prepare = node;
        if (process == nullptr) process = node;
        if (publish == nullptr) publish = node;

        return nullptr;
    }

    stream * stream::buffer::del(stream * node) {
        pokemon_develop_check(node == nullptr || node->container != this, return node);

        collection::del(this, node);

        if (node == prepare) prepare = node->next;
        if (node == process) process = node->next;
        if (node == publish) publish = node->next;

        return node;
    }

    stream * stream::buffer::gen(void) {
        return new stream(this);
    }

    void stream::buffer::trash(void) {
        stream * node = head;
        stream * successor = nullptr;

        while (node) {
            successor = node->next;

            if (node->status & stream::state::publish::end) {
                allocator::del(del(node));
                node = successor;
                continue;
            }

            break;
        }
    }

    void stream::buffer::clear(void) {
        collection::clear(this);

        publish = nullptr;
        process = nullptr;
        prepare = nullptr;
    }

    void stream::buffer::clean(void) {
        publish = nullptr;
        process = nullptr;
        prepare = nullptr;

        if (head != nullptr) {
            while (head->next != nullptr) allocator::del(collection::del(this, head));

            head->clean();
        }

        prepare = head;
        process = head;
        publish = head;
    }

    void stream::buffer::reset(void) {
        publish = nullptr;
        process = nullptr;
        prepare = nullptr;

        stream * node = head;
        stream * successor = nullptr;

        while (node) {
            successor = head->next;

            if (node->status & stream::state::publish::end) {
                allocator::del(del(node));
                node = successor;
                continue;
            }

            if (node->status & (stream::state::package::end | stream::state::process::end)) {
                node = successor;
                continue;
            }

            if (node->status & stream::state::prepare::end) {
                node->reset();
                node = successor;
                continue;
            }

            node->clean();
            node = successor;
        }
    }

}