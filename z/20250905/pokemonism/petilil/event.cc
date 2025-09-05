/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#include "event.hh"

namespace pokemonism {

    petilil::event * petilil::event::rem(petilil::event * event) {
        pokemon_training_check(event == nullptr, return nullptr);

        if (event->container != nullptr) {
            event->container->del(event);

            petilil::event::link * node = event->node;

            /**
             * 이벤트 큐에서 삭제되었다는 것으로 처리되지 않은 이벤트라고 가정할 수 있다.
             * 그렇게 때문에 `node` 는 널이 아니어야 한다.
             */
            pokemon_training_check(node == nullptr, return event);

            if (node->on() > declaration::success) node->raise(new pokemon::faint());

            node->event = nullptr;
            event->node = allocator::del(event->node);

            return event;
        }

        if (event->node != nullptr) {
            event->node->event = nullptr;
            event->node = allocator::del(event->node);
        }

        return event;
    }



}

// public:     virtual int on(void);