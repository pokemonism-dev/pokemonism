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
#include <pokemonism/pokemon/petilil.hh>
#include <pokemonism/battle.hh>

using namespace pokemonism;

int main(int argc, char ** argv) {
    pokemonism::lana * lana = pokemonism::lana::on();

    pokemonism::petilil<pokemonism::lana> * petilil = lana->capture<pokemonism::petilil<pokemonism::lana>>();

    // pokemonism::petilil<pokemonism::lana> * petilil = lana->capture<pokemonism::petilil<pokemonism::lana>>();
    //
    // lana->recall(pokemonism::battle::start(lana->go<pokemonism::petilil<pokemonism::lana>>()));

    return declaration::success;
}
