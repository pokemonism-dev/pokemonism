/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_HH__
#define   __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/memorizer.hh>

namespace pokemonism::sdk {

    template <typename elementable, unsigned long size>
    class memorizer<elementable, unsigned, size> {
    public:     static elementable * set(elementable * destination, const elementable & item);
    public:     static elementable * set(elementable * destination, elementable && item);
    public:     static elementable * set(elementable * destination, const elementable & item, unsigned long n);
    public:     static elementable * set(elementable * destination, const elementable * source, unsigned long sourceLen);
    public:     static elementable * del(elementable * destination);
    public:     static elementable * del(elementable * destination, unsigned long destinationLen);
    public:     memorizer(void);
    public:     virtual ~memorizer(void);
    public:     memorizer(const memorizer<elementable, unsigned, size> & o) = delete;
    public:     memorizer(memorizer<elementable, unsigned, size> && o) noexcept = delete;
    public:     memorizer<elementable, unsigned, size> & operator=(const memorizer<elementable, unsigned, size> & o) = delete;
    public:     memorizer<elementable, unsigned, size> & operator=(memorizer<elementable, unsigned, size> && o) noexcept = delete;
    };

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned, size>::set(elementable * destination, const elementable & item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = item;

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned, size>::set(elementable * destination, elementable && item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = std::move(item);

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned, size>::set(elementable * destination, const elementable & item, unsigned long n) {
        pokemon_develop_check(destination == nullptr || n == 0, return nullptr);

        for (unsigned long i = 0; i < n; i = i + 1) referenceof(destination + i) = item;

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned, size>::set(elementable * destination, const elementable * source, unsigned long sourceLen) {
        pokemon_develop_check(destination == nullptr || sourceLen == 0, return nullptr);

        memcpy(destination, source, sourceLen * size);

        // for (unsigned long i = 0; i < sourceLen; i = i + 1) referenceof(destination + i) = valueof(source + i);

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned, size>::del(elementable * destination) {
        pokemon_develop_check(destination == nullptr, return destination);

        return destination;
    }

    template <typename elementable, unsigned long size>
    elementable * memorizer<elementable, unsigned, size>::del(elementable * destination, unsigned long destinationLen) {
        pokemon_develop_check(destination == nullptr || destinationLen == 0, return destination);

        return destination;
    }

    template <typename elementable, unsigned long size>
    memorizer<elementable, unsigned, size>::memorizer(void) {

    }

    template <typename elementable, unsigned long size>
    memorizer<elementable, unsigned, size>::~memorizer(void) {

    }

}

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/memorizer/primitivable/one.hh>

#endif // __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_HH__