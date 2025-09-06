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
using namespace pokemonism::sdk;

static pokemonism::sdk::engine * singleton = nullptr;

static void engineOff(void) {

}

int main(int argc, char ** argv) {
    singleton = new pokemonism::sdk::engine();

    singleton->on(nullptr);

    professors::oak::tools::randomizer func = professors::oak::get<professors::oak::tools::randomizer>();

    printf("%ld\n", primitivable::to<long>(func()));

    func.valueSet(1004);

    printf("%ld\n", primitivable::to<long>(func()));

    command::event::callback::set eventSet([](command & o, unsigned int type, command::event::envelope & envelope, const command::event::exception * e) {
        printf("%ld\n", primitivable::to<long>(envelope.messagePop()));
    });

    const command::event::subscription::state::callback::function subscriptionOn = [](command::event::modifiable::subscription & subscription, unsigned int type, const command::event::exception * e) {
    };

    const command::event::subscription::state::callback::modifier subscriptionReleaseOn = [](command::event::releasable::subscription & subscription, unsigned int type, const command::event::exception * e) {
        singleton->off(nullptr);
    };

    singleton->reg(pointof(func), command::event::subscription::property::release_on_del, eventSet, subscriptionOn, subscriptionReleaseOn);

    const int ret = singleton->run();

    delete singleton;
    singleton = nullptr;

    return ret;
}
