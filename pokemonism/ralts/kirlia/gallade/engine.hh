/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GALLADE_ENGINE_HH__
#define   __POKEMONISM_GALLADE_ENGINE_HH__

#include <pokemonism/pokemon/sync.hh>
#include <pokemonism/pokemon/command.hh>

namespace pokemonism {
    namespace gallade {

        class subscription;

        class engine {
        protected:  static pokemon::sync sync;
        public:     static gallade::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::set & callback);

        public:     static gallade::subscription * del(gallade::subscription *);
        public:     static gallade::subscription * rel(gallade::subscription *);

        public:     engine(void) {}
        public:     ~engine(void) override {}
        public:     engine(const gallade::engine & o) = delete;
        public:     engine(gallade::engine && o) noexcept = delete;
        public:     gallade::engine & operator=(const gallade::engine & o) = delete;
        public:     gallade::engine & operator=(gallade::engine && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_GALLADE_ENGINE_HH__