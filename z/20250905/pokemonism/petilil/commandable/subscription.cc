/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "subscription.hh"

namespace pokemonism {

    int petilil::commandable::subscription::processOn(petilil::event::link * o) noexcept {
        pokemon_training_exit_check(o->subscriptionGet() != this, return declaration::fail);

        petilil::commandable::link * node = pokemon::cast<petilil::commandable::link *>(o);

        try {
            const int ret = petilil::commandable::processor::on(*this, node->identifierGet(), referenceof(node));
            node->returnSet(ret);
            callbackOn(node, node->identifierGet());
            return ret;
        } catch (const pokemon::faint & e) {
            node->returnSet(declaration::fail);
            node->raise(e.clone());
        } catch (const pokemonism::exception & e) {
            node->returnSet(declaration::fail);
            node->raise(new pokemon::faint(e.reason(), e.levelGet(), e));
        } catch (const std::exception & e) {
            node->returnSet(declaration::fail);
            node->raise(new pokemon::faint(e.what(), pokemon::faint::level::sleep));
        } catch (...) {
            node->returnSet(declaration::fail);
            node->raise(new pokemon::faint());
        }

        return declaration::fail;
    }

}