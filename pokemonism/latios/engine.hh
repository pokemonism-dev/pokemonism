/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_LATIOS_ENGINE_HH__
#define   __POKEMONISM_LATIOS_ENGINE_HH__

#include <pokemonism.hh>

#include <pokemonism/wattrel/engine.hh>

namespace pokemonism {
    namespace latios {

        class engine {
        public:     static void on(wattrel::engine::bootstrapper bootstrap);
        public:     static void off(wattrel::engine::terminator executor);
        public:     static int run(void);
        // TODO: IMPLEMENT THIS
        // public:     template <typename output> pokemon::subscription * reg(pokemon::general::command<output> * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n);

        protected:  engine(void);
        protected:  virtual ~engine(void);
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_LATIOS_ENGINE_HH__