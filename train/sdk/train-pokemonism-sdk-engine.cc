/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#include <pokemonism/sdk/engine.hh>
#include <pokemonism/professor/oak.hh>

using namespace pokemonism;

int main(int argc, char ** argv) {
    pokemonism::sdk::engine * engine = new pokemonism::sdk::engine();

    engine->on(nullptr);

    professors::oak::tools::randomizer command = professors::oak::get<professors::oak::tools::randomizer>();

    printf("%ld\n", pokemonism::sdk::primitivable::to<long>(command()));

    command.valueSet(1004);

    printf("%ld\n", pokemonism::sdk::primitivable::to<long>(command()));

    // public:     typedef void (*function)(command &, unsigned int, command::event::envelope &, const command::event::exception *);
    pokemonism::sdk::command::event::callback::set eventSet([](pokemonism::sdk::command & o, unsigned int type, pokemonism::sdk::command::event::envelope & envelope, const pokemonism::sdk::command::event::exception * e) {
        printf("%ld\n", pokemonism::sdk::primitivable::to<long>(envelope.messagePop()));
    });

    engine->reg(pointof(command), pokemonism::sdk::command::event::subscription::property::release_on_del, eventSet);

    const int ret = engine->run();

    delete engine;

    return ret;
}
