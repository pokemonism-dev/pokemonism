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
        template <typename elementable, typename primitivable = typographer<elementable>::primitivable, unsigned long size = typographer<elementable>::unit>
        class memorizer {
        public:     static elementable * set(elementable * destination, const elementable & item);
        public:     static elementable * set(elementable * destination, elementable && item);
        public:     static elementable * set(elementable * destination, const elementable & item, unsigned long n);
        public:     static elementable * set(elementable * destination, const elementable * source, unsigned long sourceLen);
        public:     static elementable * del(elementable * destination);
        public:     static elementable * del(elementable * destination, unsigned long destinationLen);
        public:     memorizer(void);
        public:     virtual ~memorizer(void);
        public:     memorizer(const memorizer<elementable, primitivable, size> & o) = delete;
        public:     memorizer(memorizer<elementable, primitivable, size> && o) noexcept = delete;
        public:     memorizer<elementable, primitivable, size> & operator=(const memorizer<elementable, primitivable, size> & o) = delete;
        public:     memorizer<elementable, primitivable, size> & operator=(memorizer<elementable, primitivable, size> && o) noexcept = delete;
        };

        template <typename elementable, typename primitivable, unsigned long size>
        elementable * memorizer<elementable, primitivable, size>::set(elementable * destination, const elementable & item) {
            pokemon_develop_check(destination == nullptr, return nullptr);

            new (destination) elementable(item);

            return destination;
        }

        template <typename elementable, typename primitivable, unsigned long size>
        elementable * memorizer<elementable, primitivable, size>::set(elementable * destination, elementable && item) {
            pokemon_develop_check(destination == nullptr, return nullptr);

            new (destination) elementable(std::move(item));

            return destination;
        }

        template <typename elementable, typename primitivable, unsigned long size>
        elementable * memorizer<elementable, primitivable, size>::set(elementable * destination, const elementable & item, unsigned long n) {
            pokemon_develop_check(destination == nullptr || n == 0, return nullptr);

            for (unsigned long i = 0; i < n; i = i + 1) new (destination + i) elementable(item);

            return destination;
        }

        template <typename elementable, typename primitivable, unsigned long size>
        elementable * memorizer<elementable, primitivable, size>::set(elementable * destination, const elementable * source, unsigned long sourceLen) {
            pokemon_develop_check(destination == nullptr || sourceLen == 0, return nullptr);

            for (unsigned long i = 0; i < sourceLen; i = i + 1) new (destination + i) elementable(referenceof(source + i));

            return destination;
        }

        template <typename elementable, typename primitivable, unsigned long size>
        elementable * memorizer<elementable, primitivable, size>::del(elementable * destination) {
            pokemon_develop_check(destination == nullptr, return destination);

            destination->~elementable();

            return destination;
        }

        template <typename elementable, typename primitivable, unsigned long size>
        elementable * memorizer<elementable, primitivable, size>::del(elementable * destination, unsigned long destinationLen) {
            pokemon_develop_check(destination == nullptr || destinationLen == 0, return destination);

            for (unsigned long i = 0; i < destinationLen; i = i + 1) (destination + i)->~elementable();

            return destination;
        }

        template <typename elementable, typename primitivable, unsigned long size>
        memorizer<elementable, primitivable, size>::memorizer(void) {

        }

        template <typename elementable, typename primitivable, unsigned long size>
        memorizer<elementable, primitivable, size>::~memorizer(void) {

        }
    }

    template <typename elementable, typename primitivable = typographer<elementable>::primitivable, unsigned long size = typographer<elementable>::unit>
    using memorizer = pokemonism::sdk::memorizer<elementable, primitivable, size>;

}

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/memorizer/primitivable.hh>

#endif // __POKEMONISM_SDK_MEMORIZER_HH__