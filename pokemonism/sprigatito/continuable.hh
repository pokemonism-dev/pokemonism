/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_SPRIGATITO_CONTINUABLE_HH__
#define   __POKEMONISM_SPRIGATITO_CONTINUABLE_HH__

#include <pokemonism.hh>

#include <pokemonism/sprigatito/containable.hh>

namespace pokemonism {
    namespace sprigatito {

        template <class elementable>
        class continuable : public containable<elementable> {
        public:     typedef elementable     element;
        protected:  element *       storage;
        protected:  uint64          capacity;
        protected:  uint64          size;
        public:     continuable(void) : storage(nullptr), capacity(declaration::zero), size(declaration::zero) {

                    }

        };

    }
}

#endif // __POKEMONISM_SPRIGATITO_CONTINUABLE_HH__