/**
 * @file            pokemonism/interface/runnable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_RUNNABLE_HH__
#define   __POKEMONISM_INTERFACE_RUNNABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace interface {

        class runnable {
        public:     virtual void operator()(void) = 0;
        public:     runnable(void) {}
        public:     virtual ~runnable(void) {}
        public:     runnable(const runnable & o) = delete;
        public:     runnable(runnable && o) noexcept = delete;
        public:     runnable & operator=(const runnable & o) = delete;
        public:     runnable & operator=(runnable && o) noexcept = delete;
        };


    }
}

#endif // __POKEMONISM_INTERFACE_RUNNABLE_HH__