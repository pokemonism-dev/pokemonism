/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */


#include "link.hh"

namespace pokemonism {

    petilil::event::link * petilil::event::link::rem(petilil::event::link * o) {
        pokemon_training_check(o == nullptr, return o);

        if (petilil::event * event = o->event; event != nullptr) {
            if (petilil::event::queue * container = event->container; container != nullptr) {
                container->del(event);

                if (event->on() > declaration::success) o->raise(new pokemon::faint());
            }

            event->node = nullptr;
            o->event = allocator::del(o->event);
        }

        if (o->container != nullptr) o->container->del(o);

        return o;
    }

    void petilil::event::link::raise(pokemon::faint * e) {
        pokemon_training_check(e == nullptr || container == nullptr, return);

        if (exception != nullptr) {
            container->raise(this, e);

            allocator::del(e);

            return;
        }

        exception = e;
        container->raise(this, e);
    }

}