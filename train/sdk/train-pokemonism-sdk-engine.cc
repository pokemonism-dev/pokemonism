/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#include <pokemonism/sdk/engine.hh>

using namespace pokemonism;
using namespace pokemonism::sdk;

static pokemonism::sdk::engine * singleton = nullptr;

class randomizer : public pokemonism::sdk::command {
protected:  long v;
public:     pokemonism::sdk::primitivable * operator()(void) override { return pokemonism::sdk::primitivable::from(v == 0 ? random() : v); }
public:     inline void valueSet(long value) { v = value; }
public:     inline explicit randomizer(long v) : v(v) {}
public:     inline randomizer(void) : v(declaration::zero) {}
public:     inline ~randomizer(void) override {}
public:     randomizer(const randomizer & o) : v(o.v) {}
public:     randomizer(randomizer && o) noexcept : v(o.v) { o.v = declaration::zero; }
public:     randomizer & operator=(const randomizer & o) {
                if (pointof(o) != this) v = o.v;
                return *this;
            }
public:     randomizer & operator=(randomizer && o) noexcept {
                if (pointof(o) != this) {
                    v = o.v;
                    o.v = declaration::zero;
                }
                return *this;
            }
};

int main(int argc, char ** argv) {
    singleton = new pokemonism::sdk::engine();

    singleton->on(nullptr);

    randomizer func;

    printf("%ld\n", primitivable::to<long>(func()));

    func.valueSet(1004);

    printf("%ld\n", primitivable::to<long>(func()));

    const command::event::callback::set eventSet([](command & o, unsigned int type, command::event::envelope & envelope, const command::event::exception * e) {
        printf("%ld\n", primitivable::to<long>(envelope.messagePop()));
    });

    const command::event::subscription::state::callback::function subscriptionOn = [](command::event::modifiable::subscription & subscription, unsigned int type, const command::event::exception * e) {
        printf("%d\n", type);
    };

    const command::event::subscription::state::callback::modifier subscriptionReleaseOn = [](command::event::releasable::subscription & subscription, unsigned int type, const command::event::exception * e) {
        printf("%d\n", type);
        singleton->off(nullptr);
    };

    singleton->reg(pointof(func), command::event::subscription::property::release_on_del, eventSet, subscriptionOn, subscriptionReleaseOn);

    const int ret = singleton->run();

    delete singleton;
    singleton = nullptr;

    return ret;
}
