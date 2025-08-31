/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#include <pokemonism/wattrel.hh>
#include <pokemonism/wattrel/command.hh>

namespace pokemonism {
    namespace persian {
        class command : public pokemon::command {
        protected:  long v;
        public:     pokemon::primitivable::object * operator()(void) override { return pokemon::primitivable::object::gen(v != 0 ? random() : 1004); }
        public:     explicit command(long v = 0) : v(v) {}
        public:     ~command(void) override {}
        public:     command(const command & o) = delete;
        public:     command(command && o) = delete;
        public:     command & operator=(const command & o) = delete;
        public:     command & operator=(command && o) = delete;
        };
    }
}

using namespace pokemonism;

static wattrel::engine * engine = nullptr;

static int commandEventOn(pokemon::command & command, uint32 type, pokemon::command::envelope * envelope) {
    if (envelope != nullptr) throw pokemon::exception();

    printf("event on => %u\n", type);

    return declaration::success;
}

static int commandEventRelOn(pokemon::command & command, uint32 type, pokemon::command::envelope * envelope) {
    if (envelope != nullptr) throw pokemon::exception();

    printf("event on => %u\n", type);

    if (engine != nullptr) engine->off(wattrel::t800);

    return declaration::success;
}

static int commandExceptionOn(pokemon::command & command, uint32 type, pokemon::command::envelope * envelope) {
    if (envelope == nullptr) throw pokemon::exception();


    printf("event on => %u\n", type);

    return declaration::success;
}

static int commandOutputOn(pokemon::command & command, uint32 type, pokemon::command::envelope * envelope) {
    if (envelope == nullptr) throw pokemon::exception();
    pokemon::primitivable::object * output = envelope->pop();

    printf("output => %lu\n", pokemon::primitivable::object::to::int64(output));

    return declaration::success;
}


static pokemon::command::callback::type callbacks[pokemon::command::event::type::max] = {
    commandEventOn,
    commandEventRelOn,
    commandEventOn,
    commandEventOn,
    commandExceptionOn,
    commandOutputOn
};

int main(int argc, char ** argv) {
    printf("wattrel::command::event::type::max => %u\n", wattrel::command::event::type::max);

    srandom(time(nullptr));

    engine = new wattrel::engine();
    engine->on(nullptr);

    persian::command * o = new persian::command();

    engine->reg(o, wattrel::command::subscription::property::release_object_on_rel | wattrel::command::subscription::property::release_on_del, callbacks, wattrel::command::event::type::max);

    const int ret = engine->run();

    delete engine;

    return ret;
}
