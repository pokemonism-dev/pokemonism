/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */


#include "command.hh"

#include "engine.hh"

namespace pokemonism {
    namespace gardevoir {
        namespace command {

            int subscription::on(gardevoir::node * node) {
                pokemon_develop_check(node == nullptr || dynamic_cast<gardevoir::command::node *>(node) == nullptr || node->subscriptionGet() != this, return declaration::fail);

                gardevoir::command::node * o = reinterpret_cast<gardevoir::command::node *>(node);
                const gardevoir::command::event * event = o->eventGet();

                int ret = declaration::fail;

                try {
                    ret = gardevoir::command::processor::on(*this, event->eventGet(), referenceof(o));
                } catch (const pokemon::exception & e) {
                    o->exceptionSet(e.clone());
                } catch (...) {
                    o->exceptionSet(new pokemon::exception());
                }

                eventOn(o);

                return ret;
            }

            subscription::~subscription(void)  {
                clear();

                if (container != nullptr) {
                    properties = properties & (~gardevoir::subscription::property::release_on_del);
                    container->del(this);
                }

                gardevoir::subscription::on(gardevoir::subscription::event::type::rel);

                object = ((properties & gardevoir::command::subscription::property::release_object_on_rel) ? allocator::del(object) : nullptr);

                if (subscriptionSet != nullptr) subscriptionSet = static_cast<kirlia::subscription::event::handler::set *>(allocator::rel(subscriptionSet));

                status = declaration::none;
                properties = declaration::none;
            }

            gardevoir::command::subscription * generator::reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet) {
                pokemon_develop_check(target == nullptr, return nullptr);

                gardevoir::command::subscription * subscription = new gardevoir::command::subscription(target, properties, eventSet);

                subscription->on(gardevoir::command::subscription::event::type::gen);

                gardevoir::generator::reg(subscription);

                gardevoir::engine::dispatch(new gardevoir::command::event(gardevoir::command::event::type::execute, new gardevoir::command::node(subscription)));

                return subscription;
            }

            gardevoir::command::subscription * generator::reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet, const gardevoir::command::subscription::event::handler::set & subscriptionSet) {
                pokemon_develop_check(target == nullptr, return nullptr);

                gardevoir::command::subscription * subscription = new gardevoir::command::subscription(target, properties, eventSet, subscriptionSet);

                subscription->on(gardevoir::command::subscription::event::type::gen);

                gardevoir::generator::reg(subscription);

                gardevoir::engine::dispatch(new gardevoir::command::event(gardevoir::command::event::type::execute, new gardevoir::command::node(subscription)));

                return subscription;
            }

        }
    }
}