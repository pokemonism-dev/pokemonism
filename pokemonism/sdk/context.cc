/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */


#include "context.hh"

namespace pokemonism::sdk {

    context::context(context::buffer * container) : properties(context::property::type::none), parent(nullptr) {
        pokemon_develop_check(container == nullptr, return);
        container->add(this);
    }

    context::context(unsigned char item, unsigned long n) : stream(item, n), properties(context::property::type::none), parent(nullptr) {

    }

    context::context(const unsigned char * source, unsigned long sourceLen) : stream(source, sourceLen), properties(context::property::type::none), parent(nullptr) {

    }

    context::context(void) : properties(context::property::type::none), parent(nullptr) {

    }

    context::~context(void) {
        if (container != nullptr) container->del(this);
    }

    context::context(const context & o) : stream(o), properties(context::property::type::none), parent(nullptr) {

    }

    context::context(context && o) noexcept : stream(std::move(o)), properties(context::property::type::none), parent(nullptr) {

    }

    context & context::operator=(const context & o) {
        if (pointof(o) != this) {
            stream::operator=(o);

            properties = o.properties;
        }
        return *this;
    }

    context & context::operator=(context && o) noexcept {
        if (pointof(o) != this) {
            stream::operator=(std::move(o));

            properties = o.properties;
        }
        return *this;
    }

    context::context(const stream & o) : stream(o), properties(context::property::type::none), parent(nullptr) {

    }

    context::context(stream && o) noexcept : stream(std::move(o)), properties(context::property::type::none), parent(nullptr) {

    }

    context & context::operator=(const stream & o) {
        if (pointof(o) != this) {
            stream::operator=(o);
        }
        return *this;
    }

    context & context::operator=(stream && o) noexcept {
        if (pointof(o) != this) {
            stream::operator=(std::move(o));
        }
        return *this;
    }

    context::context(const collection::stream<unsigned char> & o) : stream(o), properties(context::property::type::none), parent(nullptr) {

    }

    context::context(collection::stream<unsigned char> && o) noexcept : stream(std::move(o)), properties(context::property::type::none), parent(nullptr) {

    }

    context & context::operator=(const collection::stream<unsigned char> & o) {
        if (pointof(o) != this) {
            stream::operator=(o);
        }
        return *this;
    }

    context & context::operator=(collection::stream<unsigned char> && o) noexcept {
        if (pointof(o) != this) {
            stream::operator=(std::move(o));
        }
        return *this;
    }

}