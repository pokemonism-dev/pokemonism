/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_MEMORIZER_HH__
#define   __POKEMONISM_SDK_MEMORIZER_HH__

#include <pokemonism/sdk/exception.hh>
#include <pokemonism/sdk/typographer.hh>

namespace pokemonism::sdk {

    template <typename elementable, typename primitivable = typographer<elementable>::primitive, typename characterizable = typographer<elementable>::character, unsigned long size = typographer<elementable>::unit>
    class memorizer {
    public:     static elementable * set(elementable * destination, const elementable & item);
    public:     static elementable * set(elementable * destination, elementable && item);
    public:     static elementable * set(elementable * destination, const elementable & item, unsigned int n);
    public:     static elementable * set(elementable * destination, const elementable * source, unsigned long sourceLen);
    public:     static elementable * del(elementable * source, unsigned long sourceLen);
    public:     static elementable * del(elementable * destination);
    public:     memorizer(void);
    public:     virtual ~memorizer(void);
    public:     memorizer(const memorizer<elementable, primitivable, characterizable, size> & o) = delete;
    public:     memorizer(memorizer<elementable, primitivable, characterizable, size> && o) noexcept = delete;
    public:     memorizer<elementable, primitivable, characterizable, size> & operator=(const memorizer<elementable, primitivable, characterizable, size> & o) = delete;
    public:     memorizer<elementable, primitivable, characterizable, size> & operator=(memorizer<elementable, primitivable, characterizable, size> && o) noexcept = delete;
    };

    template <typename elementable, typename primitivable, typename characterizable, unsigned long size>
    elementable * memorizer<elementable, primitivable, characterizable, size>::set(elementable * destination, const elementable & item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        new (destination) elementable(item);

        return destination;
    }

    template <typename elementable, typename primitivable, typename characterizable, unsigned long size>
    elementable * memorizer<elementable, primitivable, characterizable, size>::set(elementable * destination, elementable && item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        new (destination) elementable(std::move(item));

        return destination;
    }

    template <typename elementable, typename primitivable, typename characterizable, unsigned long size>
    elementable * memorizer<elementable, primitivable, characterizable, size>::set(elementable * destination, const elementable & item, unsigned int n) {
        if (destination == nullptr || n == 0) return destination;

        for (unsigned long i = 0; i < n; i = i + 1) new (destination + i) elementable(item);

        return destination;
    }

    template <typename elementable, typename primitivable, typename characterizable, unsigned long size>
    elementable * memorizer<elementable, primitivable, characterizable, size>::set(elementable * destination, const elementable * source, unsigned long sourceLen) {
        pokemon_develop_check(source == nullptr && sourceLen > 0, return destination);
        pokemon_develop_check(destination == nullptr && sourceLen > 0, return destination);
        if (destination == nullptr) return destination;

        for (unsigned long i = 0; i < sourceLen; i = i + 1) new (destination + i) elementable(referenceof(source + i));

        return destination;
    }

    template <typename elementable, typename primitivable, typename characterizable, unsigned long size>
    elementable * memorizer<elementable, primitivable, characterizable, size>::del(elementable * source, unsigned long sourceLen) {
        pokemon_develop_check(source == nullptr && sourceLen > 0, return source);
        if (source == nullptr) return source;

        for (unsigned long i = 0; i < sourceLen; i = i + 1) (source + i)->~elementable();

        return source;
    }

    template <typename elementable, typename primitivable, typename characterizable, unsigned long size>
    elementable * memorizer<elementable, primitivable, characterizable, size>::del(elementable * destination) {
        if (destination != nullptr) destination->~elementable();

        return destination;
    }

    template <typename elementable, typename primitivable, typename characterizable, unsigned long size>
    memorizer<elementable, primitivable, characterizable, size>::memorizer(void) {

    }

    template <typename elementable, typename primitivable, typename characterizable, unsigned long size>
    memorizer<elementable, primitivable, characterizable, size>::~memorizer(void) {

    }

}

#endif // __POKEMONISM_SDK_MEMORIZER_HH__