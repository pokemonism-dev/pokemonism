/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "command.hh"

#include "engine.hh"

namespace pokemonism {
    namespace wattrel {
        namespace command {
            wattrel::command::subscription * generator::reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::type * callbacks, uint32 n) {
                if (target == nullptr || callbacks == nullptr || n == 0 || wattrel::command::event::type::max < n) throw pokemon::exception();

                wattrel::command::subscription * subscription = new wattrel::command::subscription(target, properties, callbacks, n);

                if (add(subscription) != declaration::success) return allocator::del(subscription);

                wattrel::command::event * event = new wattrel::command::event(wattrel::command::event::type::execute, new wattrel::command::node(subscription));

                engine->push(event);

                return subscription;
            }
        }
    }
}