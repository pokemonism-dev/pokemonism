/**
 * @file            pokemonism/interface/synchronizable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_SYNCHRONIZABLE_HH__
#define   __POKEMONISM_INTERFACE_SYNCHRONIZABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace interface {

        class synchronizable {
        public:     virtual int lock(void) = 0;
        public:     virtual int unlock(void) = 0;
        public:     virtual int wait(void) = 0;
        public:     virtual int wait(int64 second, int64 nano) = 0;
        public:     virtual int wakeup(void) = 0;
        public:     virtual int wakeup(bool all) = 0;
        public:     synchronizable(void) {}
        public:     virtual ~synchronizable(void) {}
        public:     synchronizable(const synchronizable & o) = delete;
        public:     synchronizable(synchronizable && o) noexcept = delete;
        public:     synchronizable & operator=(const synchronizable & o) = delete;
        public:     synchronizable & operator=(synchronizable && o) noexcept = delete;
        };

    }

    using synchronizable = pokemonism::interface::synchronizable;

}

#endif // __POKEMONISM_INTERFACE_SYNCHRONIZABLE_HH__