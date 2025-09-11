/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_HH__
#define   __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_HH__

#include <pokemonism/sdk/memorizer.hh>

namespace pokemonism::sdk {

    template <typename elementable, unsigned long size>
    class memorizer<elementable, unsigned char, size> {
    public:     static elementable * set(elementable * destination, const elementable & item);
    public:     static elementable * set(elementable * destination, elementable && item);
    public:     static elementable * set(elementable * destination, const elementable & item, unsigned int n);
    public:     static elementable * set(elementable * destination, const elementable * source, unsigned long sourceLen);
    public:     static elementable * del(elementable * source, unsigned long sourceLen);
    public:     static elementable * del(elementable * destination);
    public:     memorizer(void);
    public:     virtual ~memorizer(void);
    public:     memorizer(const memorizer<elementable, unsigned char, size> & o) = delete;
    public:     memorizer(memorizer<elementable, unsigned char, size> && o) noexcept = delete;
    public:     memorizer<elementable, unsigned char, size> & operator=(const memorizer<elementable, unsigned char, size> & o) = delete;
    public:     memorizer<elementable, unsigned char, size> & operator=(memorizer<elementable, unsigned char, size> && o) noexcept = delete;
    };

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned char, size>::set(elementable * destination, const elementable & item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = item;

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned char, size>::set(elementable * destination, elementable && item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = item;

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned char, size>::set(elementable * destination, const elementable & item, unsigned int n) {
        if (destination == nullptr || n == 0) return destination;

        for (unsigned long i = 0; i < n; i = i + 1) referenceof(destination + i) = item;

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned char, size>::set(elementable * destination, const elementable * source, unsigned long sourceLen) {
        pokemon_develop_check(source == nullptr && sourceLen > 0, return destination);
        pokemon_develop_check(destination == nullptr && sourceLen > 0, return destination);
        if (destination == nullptr || source == nullptr) return destination;

        for (unsigned long i = 0; i < sourceLen; i = i + 1) referenceof(destination + i) = valueof(source + i);

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned char, size>::del(elementable * source, unsigned long sourceLen) {
        pokemon_develop_throw(return source);

        // ReSharper disable once CppDFAUnreachableCode
        return source;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned char, size>::del(elementable * destination) {
        pokemon_develop_throw(return destination);
    }

    template <typename elementable, unsigned long size>
    memorizer<elementable, unsigned char, size>::memorizer(void) {

    }

    template <typename elementable, unsigned long size>
    memorizer<elementable, unsigned char, size>::~memorizer(void) {

    }

}

#include <pokemonism/sdk/memorizer/primitivable/one.hh>

#endif // __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_HH__