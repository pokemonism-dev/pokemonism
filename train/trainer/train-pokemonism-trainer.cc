/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#include <pokemonism/trainer.hh>
#include <pokemonism/trainer/lana.hh>

using namespace pokemonism;

int main(int argc, char ** argv) {
    lana * lana = lana::on();

    petilil * petilil = lana->capture<petilil>();

    return 0;
}
