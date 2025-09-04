/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#include <pokemonism/petilil.hh>

using namespace pokemonism;

class randomizer : public commandable {
protected:  long v;
public:     primitivable * operator()(void) override { return primitivable::from(v == 0 ? random() : v); }
public:     explicit randomizer(long v) : v(v) {}
public:     randomizer(void) : v(declaration::zero) {}
public:     ~randomizer(void) override {}
public:     randomizer(const randomizer & o) = delete;
public:     randomizer(randomizer && o) noexcept = delete;
public:     randomizer & operator=(const randomizer & o) = delete;
public:     randomizer & operator=(randomizer && o) noexcept = delete;
};

using command = petilil::commandable;

int main(int argc, char ** argv) {
    petilil * petilil = petilil::go();

    printf("Hi %s\n", petilil->name());

    randomizer func;
    printf("%ld", primitivable::to<unsigned long>(func()));

    command::callback callback([](pokemonism::commandable & command, unsigned int, petilil::commandable::envelope & envelope, const pokemon::faint * e){});
    //
    // {
    //     command::callback<randomizer, primitivable>::set callbackSet;
    //     callbackSet.execute = [](randomizer & command, unsigned int, petilil::command::envelope<primitivable> & envelope){};
    // }
    //
    // {
    //     command::callback<randomizer, primitivable>::set callbackSet([](randomizer & command, unsigned int, petilil::command::envelope<primitivable> & envelope){});
    // }

    return pokemon::ball::recall(petilil->start());
}