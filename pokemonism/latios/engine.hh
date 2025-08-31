/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_ENGINE_HH__
#define   __POKEMONISM_ENGINE_HH__

#include <pokemonism.hh>

#include <pokemonism/wattrel/engine.hh>

namespace pokemonism {
    namespace latios {

        class engine : public wattrel::engine {
        protected:  engine(void);
        protected:  ~engine(void) override;
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_ENGINE_HH__