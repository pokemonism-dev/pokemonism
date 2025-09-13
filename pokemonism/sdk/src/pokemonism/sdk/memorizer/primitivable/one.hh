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

    template <typename Elementable>
    class Memorizer<Elementable, unsigned, 1> {
    public:     static Elementable * set(Elementable * destination, const Elementable & item);
    public:     static Elementable * set(Elementable * destination, Elementable && item);
    public:     static Elementable * set(Elementable * destination, const Elementable & item, unsigned long n);
    public:     static Elementable * set(Elementable * destination, const Elementable * source, unsigned long sourceLen);
    public:     static Elementable * del(Elementable * destination);
    public:     static Elementable * del(Elementable * destination, unsigned long destinationLen);
    public:     Memorizer(void);
    public:     virtual ~Memorizer(void);
    public:     Memorizer(const Memorizer<Elementable, unsigned, 1> & o) = delete;
    public:     Memorizer(Memorizer<Elementable, unsigned, 1> && o) noexcept = delete;
    public:     Memorizer<Elementable, unsigned, 1> & operator=(const Memorizer<Elementable, unsigned, 1> & o) = delete;
    public:     Memorizer<Elementable, unsigned, 1> & operator=(Memorizer<Elementable, unsigned, 1> && o) noexcept = delete;
    };

    template <typename Elementable>
    Elementable * Memorizer<Elementable, unsigned, 1>::set(Elementable * destination, const Elementable & item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = item;

        return destination;
    }

    template <typename Elementable>
    Elementable * Memorizer<Elementable, unsigned, 1>::set(Elementable * destination, Elementable && item) {
        pokemon_develop_check(destination == nullptr, return nullptr);

        referenceof(destination) = std::move(item);

        return destination;
    }

    template <typename Elementable>
    Elementable * Memorizer<Elementable, unsigned, 1>::set(Elementable * destination, const Elementable & item, unsigned long n) {
        pokemon_develop_check(destination == nullptr || n == 0, return nullptr);

        memset(destination, item, n);

        return destination;
    }

    template <typename Elementable>
    Elementable * Memorizer<Elementable, unsigned, 1>::set(Elementable * destination, const Elementable * source, unsigned long sourceLen) {
        pokemon_develop_check(destination == nullptr || sourceLen == 0, return nullptr);

        memcpy(destination, source, sourceLen);

        return destination;
    }

    template <typename Elementable>
    Elementable * Memorizer<Elementable, unsigned, 1>::del(Elementable * destination) {
        pokemon_develop_check(destination == nullptr, return destination);

        return destination;
    }

    template <typename Elementable>
    Elementable * Memorizer<Elementable, unsigned, 1>::del(Elementable * destination, unsigned long destinationLen) {
        pokemon_develop_check(destination == nullptr || destinationLen == 0, return destination);

        return destination;
    }

    template <typename Elementable>
    Memorizer<Elementable, unsigned, 1>::Memorizer(void) {

    }

    template <typename Elementable>
    Memorizer<Elementable, unsigned, 1>::~Memorizer(void) {

    }

}

#endif // __POKEMONISM_SDK_MEMORIZER_PRIMITIVABLE_ONE_HH__