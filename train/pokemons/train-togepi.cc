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

using namespace pokemonism;
using namespace pokemonism::trainers;

pokemons::togepi<cynthia> * togepi = nullptr;
static pokemons::togepi<cynthia>::command::event::callback::set eventSet;
static pokemons::togepi<cynthia>::command::event::subscription::state::callback::function subscriptionOn = nullptr;
static pokemons::togepi<cynthia>::command::event::subscription::state::callback::modifier subscriptionReleaseOn = nullptr;

int main(int argc, char ** argv) {
    togepi = cynthia::gotcha<pokemons::togepi<cynthia>>();

    eventSet.execute = [](pokemonism::sdk::command & o, unsigned int type, pokemonism::sdk::command::event::envelope & envelope, const pokemonism::sdk::event::exception * problem) {
        printf("%ld\n", pokemonism::sdk::primitivable::to<long>(envelope.messagePop()));
    };

    subscriptionOn = [](pokemonism::sdk::command::event::modifiable::subscription & subscription, unsigned int type, const pokemonism::sdk::event::exception * problem) {
        printf("type => %d\n", type);
    };

    subscriptionReleaseOn = [](pokemonism::sdk::command::event::releasable::subscription & subscription, unsigned int type, const pokemonism::sdk::event::exception * problem) {
        printf("type => %d\n", type);
        togepi->goodjob();
    };

    togepi->ready();
    togepi->pound(new pokemons::togepi<cynthia>::command([]() -> pokemonism::sdk::primitivable * { return pokemonism::sdk::primitivable::from(random()); }), eventSet);
    togepi->pound(new pokemons::togepi<cynthia>::command([]() -> pokemonism::sdk::primitivable * { return pokemonism::sdk::primitivable::from(1004); }), eventSet);
    togepi->pound(new pokemons::togepi<cynthia>::command([]() -> pokemonism::sdk::primitivable * { return pokemonism::sdk::primitivable::from(1004); }), eventSet, subscriptionOn, subscriptionReleaseOn);

    return cynthia::recall(togepi->go());
}
