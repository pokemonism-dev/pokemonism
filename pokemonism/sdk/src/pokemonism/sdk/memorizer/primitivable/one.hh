/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_ONE_HH__
#define   __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_ONE_HH__

#include <pokemonism/sdk/memorizer.hh>

namespace pokemonism::sdk {

    template <typename elementable>
    class memorizer<elementable, unsigned, 1> {
    public:     static elementable * set(elementable * destination, const elementable & item);
    public:     static elementable * set(elementable * destination, elementable && item);
    public:     static elementable * set(elementable * destination, const elementable & item, unsigned long n);
    public:     static elementable * set(elementable * destination, const elementable * source, unsigned long sourceLen);
    public:     static elementable * del(elementable * destination);
    public:     static elementable * del(elementable * destination, unsigned long destinationLen);
    public:     memorizer(void);
    public:     virtual ~memorizer(void);
    public:     memorizer(const memorizer<elementable, unsigned, 1> & o) = delete;
    public:     memorizer(memorizer<elementable, unsigned, 1> && o) noexcept = delete;
    public:     memorizer<elementable, unsigned, 1> & operator=(const memorizer<elementable, unsigned, 1> & o) = delete;
    public:     memorizer<elementable, unsigned, 1> & operator=(memorizer<elementable, unsigned, 1> && o) noexcept = delete;
    };

    template <typename elementable>
    elementable * memorizer<elementable, unsigned, 1>::set(elementable * destination, const elementable & item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = item;

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned, 1>::set(elementable * destination, elementable && item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = std::move(item);

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned, 1>::set(elementable * destination, const elementable & item, unsigned long n) {
        pokemon_develop_check(destination == nullptr || n == 0, return nullptr);

        memset(destination, item, n);

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned, 1>::set(elementable * destination, const elementable * source, unsigned long sourceLen) {
        pokemon_develop_check(destination == nullptr || sourceLen == 0, return nullptr);

        memcpy(destination, source, sourceLen);

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned, 1>::del(elementable * destination) {
        pokemon_develop_check(destination == nullptr, return destination);

        return destination;
    }

    template <typename elementable>
    elementable * memorizer<elementable, unsigned, 1>::del(elementable * destination, unsigned long destinationLen) {
        pokemon_develop_check(destination == nullptr || destinationLen == 0, return destination);

        return destination;
    }

    template <typename elementable>
    memorizer<elementable, unsigned, 1>::memorizer(void) {

    }

    template <typename elementable>
    memorizer<elementable, unsigned, 1>::~memorizer(void) {

    }

}

#endif // __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_ONE_HH__