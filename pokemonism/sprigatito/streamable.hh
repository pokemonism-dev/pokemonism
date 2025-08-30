/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_SPRIGATITO_STREAMABLE_HH__
#define   __POKEMONISM_SPRIGATITO_STREAMABLE_HH__

#include <pokemonism.hh>

#include <pokemonism/sprigatito/continuable.hh>

namespace pokemonism {
    namespace sprigatito {
        template <typename elementable>
        class streamable : public continuable<elementable> {
        public:     typedef elementable element;
        protected:  uint64 position;
        public:     streamable(void) : continuable<elementable>(), position(declaration::zero) {}
        };
    }
}

#endif // __POKEMONISM_SPRIGATITO_STREAMABLE_HH__