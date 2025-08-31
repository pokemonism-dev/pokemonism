/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_GENERATOR_HH__
#define   __POKEMONISM_WATTREL_GENERATOR_HH__

#include <pokemonism.hh>

#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {
    namespace wattrel {
        class subscription;
        class engine;

        class generator {
        public:     typedef psyduck::linked::list<generator, subscription> collection;
        protected:  wattrel::engine * engine;
        protected:  uint64 size;
        protected:  wattrel::subscription * head;
        protected:  wattrel::subscription * tail;
        public:     int add(wattrel::subscription * o);
        public:     int del(wattrel::subscription * o);
        public:     virtual void clear(void);
        public:     explicit generator(wattrel::engine * engine) : engine(engine), size(0), head(nullptr), tail(nullptr) {}
        public:     generator(void) : engine(nullptr), size(0), head(nullptr), tail(nullptr) {}
        public:     virtual ~generator(void) { clear(); }
        public:     generator(const generator & o) = delete;
        public:     generator(generator && o) noexcept = delete;
        public:     generator & operator=(const generator & o) = delete;
        public:     generator & operator=(generator && o) noexcept = delete;
        public:     friend collection;
        public:     friend wattrel::subscription;
        };
    }
}

#endif // __POKEMONISM_WATTREL_GENERATOR_HH__