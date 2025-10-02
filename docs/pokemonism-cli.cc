/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#include <cstdio>

// namespace pokemonism {
//
//     class trainer {
//
//     };
//
//     class pokemon {
//     public:     virtual const char * name(void) const = 0;
//     public:     virtual pokemon * ready(void) = 0;
//     public:     virtual pokemon * fight(void) = 0;
//     public:     virtual int resultGet(void) = 0;
//     };
//
//     // template <typename monsterizable>
//     // class pokeball {
//     // protected:  monsterizable monster;
//     //
//     // };
//
//     class lana : public trainer {
//     public:     template <typename monsterizable = pokemon> static monsterizable * gotcha(void) {
//         return new monsterizable();
//     }
//     public:     template <typename monsterizable = pokemon> static int recall(monsterizable * monster) {
//         const int ret = monster->resultGet();
//         delete monster;
//         return ret;
//     }
//     public:     static void recall(pokemon * o);
//     };
//
//
//     template <typename trainerizable>
//     class snorlax : public pokemon {
//     public:     const char * name(void) const { return "snorlax"; }
//     public:     int resultGet() override { return 1;}
//     public:     snorlax<trainerizable> * ready(void) override {
//         return this;
//     }
//     public:     snorlax<trainerizable> * fight(void) override {
//         return this;
//     }
//     protected:  snorlax(void) {}
//     protected:  ~snorlax(void) {}
//     public:     friend trainerizable;
//     public:     friend trainer;
//     };
// }
//
// using namespace pokemonism;
//
// int main(int argc, char ** argv) {
//
//     snorlax<lana> * monster = lana::gotcha<snorlax<lana>>();        // 친구가 된다.
//
//
//     printf("%s\n", monster->name());
//
//     monster->ready()
//             ->fight();
//
//     printf("%d\n", lana::recall(monster));
//
//     pok
//
//     return 0;
// }

PokemonismSdk::Vulkan
pokemonism::sdk::vulkan

int main(int argc, char ** argv) {
    // LinkedList::del(...);
    // LinkedList::add(...);
    // linked::list::del(...);

    return 0;
}
