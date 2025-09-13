/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_SDK_MEMORIZER_HH__
#define   __POKEMONISM_SDK_MEMORIZER_HH__

#include <pokemonism/sdk/exception.hh>
#include <pokemonism/sdk/typographer.hh>

namespace pokemonism {
    namespace sdk {
        template <typename Elementable, typename Primitivable = Typographer<Elementable>::PrimitiveType, unsigned long size = Typographer<Elementable>::unit>
        class Memorizer {
        public:     static Elementable * set(Elementable * destination, const Elementable & item);
        public:     static Elementable * set(Elementable * destination, Elementable && item);
        public:     static Elementable * set(Elementable * destination, const Elementable & item, unsigned long n);
        public:     static Elementable * set(Elementable * destination, const Elementable * source, unsigned long sourceLen);
        public:     static Elementable * del(Elementable * destination);
        public:     static Elementable * del(Elementable * destination, unsigned long destinationLen);
        public:     Memorizer(void);
        public:     virtual ~Memorizer(void);
        public:     Memorizer(const Memorizer<Elementable, Primitivable, size> & o) = delete;
        public:     Memorizer(Memorizer<Elementable, Primitivable, size> && o) noexcept = delete;
        public:     Memorizer<Elementable, Primitivable, size> & operator=(const Memorizer<Elementable, Primitivable, size> & o) = delete;
        public:     Memorizer<Elementable, Primitivable, size> & operator=(Memorizer<Elementable, Primitivable, size> && o) noexcept = delete;
        };

        template <typename Elementable, typename Primitivable, unsigned long size>
        Elementable * Memorizer<Elementable, Primitivable, size>::set(Elementable * destination, const Elementable & item) {
            pokemon_develop_check(destination == nullptr, return nullptr);

            new (destination) Elementable(item);

            return destination;
        }

        template <typename Elementable, typename Primitivable, unsigned long size>
        Elementable * Memorizer<Elementable, Primitivable, size>::set(Elementable * destination, Elementable && item) {
            pokemon_develop_check(destination == nullptr, return nullptr);

            new (destination) Elementable(std::move(item));

            return destination;
        }

        template <typename Elementable, typename Primitivable, unsigned long size>
        Elementable * Memorizer<Elementable, Primitivable, size>::set(Elementable * destination, const Elementable & item, unsigned long n) {
            pokemon_develop_check(destination == nullptr || n == 0, return nullptr);

            for (unsigned long i = 0; i < n; i = i + 1) new (destination + i) Elementable(item);

            return destination;
        }

        template <typename Elementable, typename Primitivable, unsigned long size>
        Elementable * Memorizer<Elementable, Primitivable, size>::set(Elementable * destination, const Elementable * source, unsigned long sourceLen) {
            pokemon_develop_check(destination == nullptr || sourceLen == 0, return nullptr);

            for (unsigned long i = 0; i < sourceLen; i = i + 1) new (destination + i) Elementable(referenceof(source + i));

            return destination;
        }

        template <typename Elementable, typename Primitivable, unsigned long size>
        Elementable * Memorizer<Elementable, Primitivable, size>::del(Elementable * destination) {
            pokemon_develop_check(destination == nullptr, return destination);

            destination->~Elementable();

            return destination;
        }

        template <typename Elementable, typename Primitivable, unsigned long size>
        Elementable * Memorizer<Elementable, Primitivable, size>::del(Elementable * destination, unsigned long destinationLen) {
            pokemon_develop_check(destination == nullptr || destinationLen == 0, return destination);

            for (unsigned long i = 0; i < destinationLen; i = i + 1) (destination + i)->~Elementable();

            return destination;
        }

        template <typename Elementable, typename Primitivable, unsigned long size>
        Memorizer<Elementable, Primitivable, size>::Memorizer(void) {

        }

        template <typename Elementable, typename Primitivable, unsigned long size>
        Memorizer<Elementable, Primitivable, size>::~Memorizer(void) {

        }
    }

    template <typename Elementable, typename Primitivable = Typographer<Elementable>::PrimitiveType, unsigned long size = Typographer<Elementable>::unit>
    using Memorizer = pokemonism::sdk::Memorizer<Elementable, Primitivable, size>;

}

#include <pokemonism/sdk/memorizer/primitivable.hh>

#endif // __POKEMONISM_SDK_MEMORIZER_HH__