/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_PERSIAN_HH__
#define   __POKEMONISM_PERSIAN_HH__

#include <pokemonism.hh>
#include <pokemonism/pokemon/generic/lambda/command.hh>

namespace pokemonism {
    namespace persian {

        class command : public pokemon::command {
        protected:  long value;
        public:     command::output * operator()(void) override { return primitivable::object::gen(value == 0 ? random() : value); }
        public:     explicit command(long v) : value(v) {}
        public:     command(void) : value(declaration::zero) {}
        public:     ~command(void) override {}
        public:     command(const persian::command & o) = delete;
        public:     command(persian::command && o) noexcept = delete;
        public:     persian::command & operator=(const persian::command & o) = delete;
        public:     persian::command & operator=(persian::command && o) noexcept = delete;
        };

        namespace generic {
            template <class outputable = primitivable::object>
            class command : public pokemon::generic::command<outputable> {
            public:     command(void) {}
            public:     ~command(void) override {}
            public:     command(const command & o) = delete;
            public:     command(command && o) noexcept = delete;
            public:     command & operator=(const command & o) = delete;
            public:     command & operator=(command && o) noexcept = delete;
            };
        }

        class output : public primitivable::object {
        protected:  int64 second;
        protected:  int64 nano;
        public:     output(void) : second(0), nano(0) {
            struct timespec spec;
            clock_gettime(CLOCK_REALTIME, pointof(spec));
        }
        public:     ~output(void) override {}
        public:     output(const output & o) = delete;
        public:     output(output && o) noexcept = delete;
        public:     output & operator=(const output & o) = delete;
        public:     output & operator=(output && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_PERSIAN_HH__