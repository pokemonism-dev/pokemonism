/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_ONE_HH__
#define   __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_ONE_HH__

#include <pokemonism/sdk/memorizer.hh>

namespace pokemonism::sdk {

    template <typename elementable>
    class memorizer<elementable, unsigned char, 1> {
    public:     static elementable * set(elementable * destination, const elementable & item);
    public:     static elementable * set(elementable * destination, elementable && item);
    public:     static elementable * set(elementable * destination, const elementable & item, unsigned int n);
    public:     static elementable * set(elementable * destination, const elementable * source, unsigned long sourceLen);
    public:     static elementable * del(elementable * source, unsigned long sourceLen);
    public:     static elementable * del(elementable * destination);
    public:     memorizer(void);
    public:     virtual ~memorizer(void);
    public:     memorizer(const memorizer<elementable, unsigned char, 1> & o) = delete;
    public:     memorizer(memorizer<elementable, unsigned char, 1> && o) noexcept = delete;
    public:     memorizer<elementable, unsigned char, 1> & operator=(const memorizer<elementable, unsigned char, 1> & o) = delete;
    public:     memorizer<elementable, unsigned char, 1> & operator=(memorizer<elementable, unsigned char, 1> && o) noexcept = delete;
    };

    template <typename elementable>
    elementable * memorizer<elementable, unsigned char, 1>::set(elementable * destination, const elementable & item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = item;

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned char, 1>::set(elementable * destination, elementable && item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = item;

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned char, 1>::set(elementable * destination, const elementable & item, unsigned int n) {
        if (destination == nullptr || n == 0) return destination;

        memset(destination, item, n);

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned char, 1>::set(elementable * destination, const elementable * source, unsigned long sourceLen) {
        pokemon_develop_check(source == nullptr && sourceLen > 0, return destination);
        pokemon_develop_check(destination == nullptr && sourceLen > 0, return destination);
        if (destination == nullptr || source == nullptr) return destination;

        memcpy(destination, source, sourceLen);

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned char, 1>::del(elementable * source, unsigned long sourceLen) {
        pokemon_develop_throw("", return source);
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned char, 1>::del(elementable * destination) {
        pokemon_develop_throw("", return destination);
    }

    template <typename elementable>
    memorizer<elementable, unsigned char, 1>::memorizer(void) {

    }

    template <typename elementable>
    memorizer<elementable, unsigned char, 1>::~memorizer(void) {

    }

}

#endif // __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_ONE_HH__