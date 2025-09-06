/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#include <pokemonism/pokemons/togepi.hh>
#include <pokemonism/trainers/cynthia.hh>

using namespace pokemonism::trainers;



pokemonism::pokemons::togepi<cynthia> * togepi = nullptr;

template <trainername trainerizable> using Togepi = pokemonism::pokemons::togepi<trainerizable>;

using command = pokemonism::sdk::command;
using exception = pokemonism::sdk::event::exception;
using primitivable = pokemonism::sdk::primitivable;

namespace functional {
    using command = pokemonism::sdk::functional::command;
}

static command::event::callback::set eventSet;
static command::event::subscription::state::callback::function subscriptionOn = nullptr;
static command::event::subscription::state::callback::modifier subscriptionReleaseOn = nullptr;

int main(int argc, char ** argv) {
    togepi = cynthia::gotcha<Togepi<cynthia>>();

    eventSet.execute = [](command & o, unsigned int type, command::event::envelope & envelope, const exception * problem) {
        printf("%ld\n", primitivable::to<long>(envelope.messagePop()));
    };

    subscriptionOn = [](command::event::modifiable::subscription & subscription, unsigned int type, const exception * problem) {
        printf("type => %d\n", type);
    };

    subscriptionReleaseOn = [](command::event::releasable::subscription & subscription, unsigned int type, const exception * problem) {
        printf("type => %d\n", type);
        togepi->goodjob();
    };

    togepi->ready();
    // functionable::command
    togepi->reg(new functional::command([]() -> primitivable * { return primitivable::from(random()); }), eventSet);
    togepi->reg(new functional::command([]() -> primitivable * { return primitivable::from(1004); }), eventSet);
    togepi->reg(new functional::command([]() -> primitivable * { return primitivable::from(1004); }), eventSet, subscriptionOn, subscriptionReleaseOn);

    return cynthia::recall(togepi->go());
}
