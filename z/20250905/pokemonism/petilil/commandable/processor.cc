/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "processor.hh"

namespace pokemonism {

    int petilil::commandable::processor::on(petilil::commandable::subscription & o, unsigned int type, petilil::commandable::link & node) {
        pokemon_training_check(o.finishChk() || o.objectGet() == nullptr, return declaration::fail);

        if (type == petilil::commandable::event::execute) {
            pokemonism::commandable & func = referenceof(o.objectGet());

            primitivable * output = func();

            node.outputSet(output);
            o.executeSet();

            return o.completeChk() ? declaration::success : declaration::again;
        }

        return declaration::fail;
    }

}