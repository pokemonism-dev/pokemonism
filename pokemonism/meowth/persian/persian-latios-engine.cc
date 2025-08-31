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

static int commandEventOn(pokemon::generic::lambda::command<persian::output> & command, uint32 type, pokemon::generic::lambda::command<persian::output>::envelope * envelope) {
    if (envelope != nullptr) throw pokemon::exception();

    printf("event on => %u\n", type);

    return declaration::success;
}

static int commandEventRelOn(pokemon::generic::lambda::command<persian::output> & command, uint32 type, pokemon::generic::lambda::command<persian::output>::envelope * envelope) {
    if (envelope != nullptr) throw pokemon::exception();

    printf("event on => %u\n", type);

    latios::engine::off(latios::engine::T - 1000, wattrel::engine::T - 800);

    return declaration::success;
}

static int commandExceptionOn(pokemon::generic::lambda::command<persian::output> & command, uint32 type, pokemon::generic::lambda::command<persian::output>::envelope * envelope) {
    if (envelope == nullptr) throw pokemon::exception();


    printf("event on => %u\n", type);

    return declaration::success;
}

static int commandOutputOn(pokemon::generic::lambda::command<persian::output> & command, uint32 type, pokemon::generic::lambda::command<persian::output>::envelope * envelope) {
    if (envelope == nullptr) throw pokemon::exception();
    pokemon::primitivable::object * output = envelope->pop();

    printf("output => %lu\n", pokemon::primitivable::object::to::int64(output));

    return declaration::success;
}


static pokemon::generic::lambda::command<persian::output>::callback::type callbacks[pokemon::command::event::type::max] = {
    commandEventOn,
    commandEventRelOn,
    commandEventOn,
    commandEventOn,
    commandExceptionOn,
    commandOutputOn
};

int main(int argc, char ** argv) {
    latios::engine::on(nullptr, nullptr);

    latios::engine::commandReg<pokemon::generic::lambda::command<persian::output>>(
        new pokemon::generic::lambda::command<persian::output>([]() -> persian::output * { return nullptr; }),
        latios::command::subscription<pokemon::generic::lambda::command<persian::output>>::property::release_object_on_rel |
                latios::command::subscription<pokemon::generic::lambda::command<persian::output>>::property::release_on_del,
                callbacks, wattrel::command::event::type::max
        );


    return latios::engine::run(0);
}