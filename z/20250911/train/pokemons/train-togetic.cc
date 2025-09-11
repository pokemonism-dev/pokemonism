/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#include <pokemonism/pokemons/togepi.hh>
#include <pokemonism/pokemons/togepi/togetic.hh>
#include <pokemonism/trainers/cynthia.hh>
#include <pokemonism/sdk/generic/functional/command.hh>

using namespace pokemonism;
using namespace pokemonism::trainers;

pokemonism::pokemons::togetic<cynthia> * togetic = nullptr;

using primitivable = pokemonism::sdk::primitivable;
using exception = pokemonism::sdk::event::exception;
template <typename outputable = primitivable> using command = pokemonism::sdk::generic::command<outputable>;
template <typename commandable, typename outputable> using envelope = pokemonism::sdk::templateable::command::envelope<commandable, outputable>;

namespace functional {
    template <typename outputable = primitivable> using command = pokemonism::sdk::generic::functional::command<outputable>;
}

namespace modifiable {
    template <typename commandable, typename outputable> using subscription = pokemonism::sdk::templateable::command::modifiable::subscription<commandable, outputable>;
}

namespace releasable {
    template <typename commandable, typename outputable> using subscription = pokemonism::sdk::templateable::command::releasable::subscription<commandable, outputable>;
}

struct callback {
public:     template <typename commandable, typename outputable> using set = pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set;
public:     struct subscription {
            public:     template <typename commandable, typename outputable> using on = pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function;
            public:     template <typename commandable, typename outputable> using rel = pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier;
            };
};

class primitive : public pokemonism::sdk::primitivable {
protected:  int value;
public:     int valueGet(void) const { return value; }
public:     explicit primitive(int value) : value(value) {}
public:     primitive(void) : value(declaration::zero) {}
public:     ~primitive(void) override {}
public:     primitive(const primitive & o) : value(o.value) {}
public:     primitive(primitive && o) noexcept : value(o.value) { o.value = declaration::zero; }
public:     primitive & operator=(const primitive & o) {
    if (pointof(o) != this) value = o.value;
    return *this;
}
public:     primitive & operator=(primitive && o) noexcept {
    if (pointof(o) != this) {
        value = o.value;
        o.value = declaration::zero;
    }
    return *this;
}
};

int main(int argc, char ** argv) {
    togetic = pokemons::togepi<cynthia>::evolve<void>(cynthia::gotcha<pokemons::togepi<cynthia>>());

    callback::set<functional::command<primitive>, primitive> eventSet([](functional::command<primitive> & o, unsigned int type, envelope<functional::command<primitive>, primitive> & envelope, const exception * problem) {
        if (const primitive * output = envelope.messagePop(); output != nullptr) {
            printf("value: %d\n", output->valueGet());
            delete output;
        }
    });

    callback::subscription::on<functional::command<primitive>, primitive> subscriptionOn = [](modifiable::subscription<functional::command<primitive>, primitive> & subscription, unsigned int type, const exception * problem) {
        printf("type => %d\n", type);
    };

    callback::subscription::rel<functional::command<primitive>, primitive> subscriptionReleaseOn = [](releasable::subscription<functional::command<primitive>, primitive> & subscription, unsigned int type, const exception * problem) {
        printf("type => %d\n", type);
        togetic->goodjob();
    };

    togetic->ready();

    togetic->genericReg(new functional::command<primitive>([]() -> primitive * { return new primitive(random()); }), eventSet);
    togetic->genericReg(new functional::command<primitive>([]() -> primitive * { return new primitive(1004); }), eventSet);
    togetic->genericReg(new functional::command<primitive>([]() -> primitive * { return new primitive(random()); }), eventSet, subscriptionOn);

    togetic->genericRepeatReg(new functional::command<primitive>([]() -> primitive * { return new primitive(1004); }), 10, eventSet, subscriptionOn, subscriptionReleaseOn);

    return cynthia::recall(togetic->go());
}
