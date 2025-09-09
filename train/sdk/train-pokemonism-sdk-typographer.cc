/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */

#include <cstdio>
#include <pokemonism/sdk/typographer.hh>
#include <pokemonism/sdk/collection/continuous.hh>

using namespace pokemonism::sdk;

int main(int argc, char ** argv) {

    typographer<int *> o;
    printf("%s\n", typographer<int *>::name);

    collection::continuous<int *> container;

    printf("%s\n", collection::continuous<int *>::name);



    return 0;
}