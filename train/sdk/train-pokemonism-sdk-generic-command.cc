/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#include <pokemonism/sdk/lambdable/pure/command.hh>
#include <pokemonism/sdk/templateable/engine.hh>
#include <pokemonism/sdk/templateable/command.hh>

using namespace pokemonism;
using namespace pokemonism::sdk;

templateable::engine * singleton = nullptr;

// class randomizer : public pokemonism::sdk::command {
// protected:  long v;
// public:     pokemonism::sdk::primitivable * operator()(void) override { return pokemonism::sdk::primitivable::from(v == 0 ? random() : v); }
// public:     inline void valueSet(long value) { v = value; }
// public:     inline explicit randomizer(long v) : v(v) {}
// public:     inline randomizer(void) : v(declaration::zero) {}
// public:     inline ~randomizer(void) override {}
// public:     randomizer(const randomizer & o) : v(o.v) {}
// public:     randomizer(randomizer && o) noexcept : v(o.v) { o.v = declaration::zero; }
// public:     randomizer & operator=(const randomizer & o) {
//                 if (pointof(o) != this) v = o.v;
//                 return *this;
//             }
// public:     randomizer & operator=(randomizer && o) noexcept {
//                 if (pointof(o) != this) {
//                     v = o.v;
//                     o.v = declaration::zero;
//                 }
//                 return *this;
//             }
// };

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
    singleton = new templateable::engine();

    singleton->on();

    lambdable::pure::command<primitive> randomizer([]() -> primitive * {
        return new primitive(static_cast<int>(random()));
    });

    const templateable::command::event::callback<lambdable::pure::command<primitive>, primitive>::set eventSet([](lambdable::pure::command<primitive> & o, unsigned int type, templateable::command::envelope<lambdable::pure::command<primitive>, primitive> & envelope, const templateable::command::exception * e) {
        if (const primitive * output = envelope.messagePop(); output != nullptr) {
            printf("value: %d\n", output->valueGet());
            delete output;
        }
    });

    const templateable::command::subscription<lambdable::pure::command<primitive>, primitive>::state::callback::function subscriptionOn = [](templateable::command::modifiable::subscription<lambdable::pure::command<primitive>, primitive> & subscription, unsigned int type, const command::event::exception * e) {
        printf("%d\n", type);
    };
    // templateable::command::subscription<primitive, lambdable::pure::command<primitive>>::state::callback::function
    const templateable::command::subscription<lambdable::pure::command<primitive>, primitive>::state::callback::modifier subscriptionReleaseOn = [](templateable::command::releasable::subscription<lambdable::pure::command<primitive>, primitive> & subscription, unsigned int type, const command::event::exception * e) {
        printf("%d\n", type);
    };

    // const command::event::subscription::state::callback::modifier subscriptionReleaseOn = [](command::event::releasable::subscription & subscription, unsigned int type, const command::event::exception * e) {
    //     printf("%d\n", type);
    //     singleton->off(nullptr);
    // };

    templateable::engine::commandReg(singleton, pointof(randomizer), command::event::subscription::property::release_on_del, eventSet);

    templateable::engine::commandReg(singleton, pointof(randomizer), command::event::subscription::property::release_on_del, eventSet, subscriptionOn);

    // singleton->reg<primitive, lambdable::pure::command<primitive>>(pointof(randomizer), command::event::subscription::property::release_on_del, eventSet, subscriptionOn);

    // templateable::engine::commandReg(singleton, pointof(randomizer), command::event::subscription::property::release_on_del, eventSet, subscriptionOn);


    // singleton->reg(pointof(randomizer), command::event::subscription::property::release_on_del, eventSet, (templateable::command::subscription<primitive, lambdable::pure::command<primitive>>::state::callback::function) subscriptionOn);


    const int ret = singleton->run();

    delete singleton;
    singleton = nullptr;

    return ret;
}
