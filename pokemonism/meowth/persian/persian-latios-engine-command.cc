/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#include <pokemonism/latios/engine.hh>
#include <pokemonism/pokemon/generic/lambda/command.hh>

namespace pokemonism {
    namespace persian {
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

using namespace pokemonism;

int main(int argc, char ** argv) {
    latios::engine::on();

    return latios::engine::run();
}