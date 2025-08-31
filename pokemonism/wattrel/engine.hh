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

namespace pokemonism {

    namespace wattrel {

        class engine {
        protected:  typedef void (*terminator)(engine * o);
        protected:  typedef void (*bootstrapper)(engine & o);
        public:     static int run(void);
        public:     static engine & on(bootstrapper bootstrap);
        public:     static void off(engine::terminator execute);
        protected:  engine::terminator cancel;
        protected:  engine(void);
        protected:  virtual ~engine(void);
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };
    }

}

#endif // __POKEMONISM_ENGINE_HH__