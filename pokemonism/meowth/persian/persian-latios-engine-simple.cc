/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#include <pokemonism/latios.hh>
#include <pokemonism/latios/command.hh>

namespace pokemonism {
    namespace persian {
        class example : public primitivable::object {
        public:     typedef primitivable::object output;
        public:     struct tag {};
        public:     example(void) {}
        public:     ~example(void) override {}
        };

        class genericCommand : public pokemon::generic::command<persian::example> {
        public:     genericCommand(void) {}
        public:     ~genericCommand(void) override {}
        };

    }
}

using namespace pokemonism;

int main(int argc, char ** argv) {
    latios::engine::on(nullptr, nullptr);

    latios::command::envelope<primitivable::object> envelope;

    pokemon::generic::command<persian::example> * commandPtr = nullptr;

    printf("%s\n", latios::subscription<persian::example>::name);

    printf("%s\n", latios::subscription<pokemon::generic::command<persian::example>>::name);

    latios::subscription<persian::genericCommand> * command = nullptr;

    printf("%s\n", latios::subscription<persian::genericCommand>::name);

    printf("%s\n", latios::command::subscription<persian::genericCommand>::name);


    return latios::engine::run(1);
}
