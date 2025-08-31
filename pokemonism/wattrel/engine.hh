/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_ENGINE_HH__
#define   __POKEMONISM_WATTREL_ENGINE_HH__

#include <pokemonism.hh>

#include <pokemonism/pokemon.hh>
#include <pokemonism/pokemon/allocator.hh>

#include <pokemonism/wattrel/subscription.hh>
#include <pokemonism/wattrel/command.hh>

namespace pokemonism {

    namespace wattrel {

        class engine {
        public:     typedef void (*terminator)(engine * o);
        public:     typedef void (*bootstrapper)(engine & o);
        public:     struct generator {
                    public:     struct set {
                                public:     command::generator * command;
                                public:     inline set(void) : command(nullptr) {}
                                public:     inline ~set(void);
                                };
                    };
        public:     virtual int run(void);
        public:     virtual void on(bootstrapper bootstrap);
        public:     virtual void off(engine::terminator executor);
        public:     virtual pokemon::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n);
        protected:  engine::terminator cancel;
        protected:  engine::generator::set generator;
        public:     engine(void);
        public:     virtual ~engine(void);
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };

        engine::generator::set::~set(void) {
            command = pokemon::allocator::del(command);
        }
    }
}

#endif // __POKEMONISM_WATTREL_ENGINE_HH__