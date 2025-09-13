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

#include <pokemonism/sdk/memorizer.hh>

namespace pokemonism::sdk {

    template <typename Elementable, unsigned long size>
    class Memorizer<Elementable, unsigned, size> {
    public:     static Elementable * set(Elementable * destination, const Elementable & item);
    public:     static Elementable * set(Elementable * destination, Elementable && item);
    public:     static Elementable * set(Elementable * destination, const Elementable & item, unsigned long n);
    public:     static Elementable * set(Elementable * destination, const Elementable * source, unsigned long sourceLen);
    public:     static Elementable * del(Elementable * destination);
    public:     static Elementable * del(Elementable * destination, unsigned long destinationLen);
    public:     Memorizer(void);
    public:     virtual ~Memorizer(void);
    public:     Memorizer(const Memorizer<Elementable, unsigned, size> & o) = delete;
    public:     Memorizer(Memorizer<Elementable, unsigned, size> && o) noexcept = delete;
    public:     Memorizer<Elementable, unsigned, size> & operator=(const Memorizer<Elementable, unsigned, size> & o) = delete;
    public:     Memorizer<Elementable, unsigned, size> & operator=(Memorizer<Elementable, unsigned, size> && o) noexcept = delete;
    };

    template <typename Elementable, unsigned long size>
    Elementable * Memorizer<Elementable, unsigned, size>::set(Elementable * destination, const Elementable & item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = item;

        return destination;
    }

    template <typename Elementable, unsigned long size>
    Elementable * Memorizer<Elementable, unsigned, size>::set(Elementable * destination, Elementable && item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = std::move(item);

        return destination;
    }

    template <typename Elementable, unsigned long size>
    Elementable * Memorizer<Elementable, unsigned, size>::set(Elementable * destination, const Elementable & item, unsigned long n) {
        pokemon_develop_check(destination == nullptr || n == 0, return nullptr);

        for (unsigned long i = 0; i < n; i = i + 1) referenceof(destination + i) = item;

        return destination;
    }

    template <typename Elementable, unsigned long size>
    Elementable * Memorizer<Elementable, unsigned, size>::set(Elementable * destination, const Elementable * source, unsigned long sourceLen) {
        pokemon_develop_check(destination == nullptr || sourceLen == 0, return nullptr);

        for (unsigned long i = 0; i < sourceLen; i = i + 1) referenceof(destination + i) = valueof(source + i);

        return destination;
    }

    template <typename Elementable, unsigned long size>
    Elementable * Memorizer<Elementable, unsigned, size>::del(Elementable * destination) {
        pokemon_develop_check(destination == nullptr, return destination);

        return destination;
    }

    template <typename Elementable, unsigned long size>
    Elementable * Memorizer<Elementable, unsigned, size>::del(Elementable * destination, unsigned long destinationLen) {
        pokemon_develop_check(destination == nullptr || destinationLen == 0, return destination);

        return destination;
    }

    template <typename Elementable, unsigned long size>
    Memorizer<Elementable, unsigned, size>::Memorizer(void) {

    }

    template <typename Elementable, unsigned long size>
    Memorizer<Elementable, unsigned, size>::~Memorizer(void) {

    }

}

#endif // __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_HH__