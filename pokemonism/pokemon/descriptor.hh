/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_DESCRIPTOR_HH__
#define   __POKEMONISM_DESCRIPTOR_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {

        class descriptor {
        protected:  int value;
        public:     descriptor(void) : value(declaration::invalid) {}
        public:     virtual ~descriptor(void) {}
        public:     descriptor(const descriptor & o) = delete;
        public:     descriptor(descriptor && o) noexcept = delete;
        public:     descriptor & operator=(const descriptor & o) = delete;
        public:     descriptor & operator=(descriptor && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_DESCRIPTOR_HH__