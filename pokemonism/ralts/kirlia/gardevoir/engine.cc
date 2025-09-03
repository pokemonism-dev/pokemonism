/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */


#include "engine.hh"

#include "queue.hh"

namespace pokemonism {
    namespace gardevoir {

        pokemon::sync                       gardevoir::engine::sync;
        gardevoir::engine::generator::set   gardevoir::engine::generator;
        gardevoir::queue *                  gardevoir::engine::queue = nullptr;
        gardevoir::engine *                 gardevoir::engine::singleton = nullptr;
        gardevoir::engine::terminator       gardevoir::engine::cancel;

        gardevoir::command::subscription * engine::reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet) {
            pokemon_develop_check(target == nullptr || gardevoir::engine::generator.command == nullptr, return nullptr);

            if (cancel != nullptr) {
                if (properties & gardevoir::command::subscription::property::release_object_on_rel) delete target;

                return nullptr;
            }

            return gardevoir::engine::generator.command->reg(target, properties, eventSet);
        }

        gardevoir::command::subscription * engine::reg(pokemon::command * target, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet) {
            pokemon_develop_check(target == nullptr || gardevoir::engine::generator.command == nullptr, return nullptr);

            if (cancel != nullptr) {
                if (properties & gardevoir::command::subscription::property::release_object_on_rel) delete target;

                return nullptr;
            }

            return gardevoir::engine::generator.command->reg(target, properties, eventSet, reinterpret_cast<const gardevoir::command::subscription::event::handler::set &>(subscriptionSet));
        }

        gardevoir::command::subscription * engine::reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet) {
            pokemon_develop_check(target == nullptr || gardevoir::engine::generator.command == nullptr, return nullptr);

            if (cancel != nullptr) {
                if (properties & gardevoir::command::subscription::property::release_object_on_rel) delete target;

                return nullptr;
            }

            return gardevoir::engine::generator.command->reg(target, repeat, properties, eventSet);
        }

        gardevoir::command::subscription * engine::reg(pokemon::command * target, int32 repeat, uint32 properties, const pokemon::command::event::handler::set & eventSet, const kirlia::command::subscription::event::handler::set & subscriptionSet) {
            pokemon_develop_check(target == nullptr || gardevoir::engine::generator.command == nullptr, return nullptr);

            if (cancel != nullptr) {
                if (properties & gardevoir::command::subscription::property::release_object_on_rel) delete target;

                return nullptr;
            }

            return gardevoir::engine::generator.command->reg(target, repeat, properties, eventSet, reinterpret_cast<const gardevoir::command::subscription::event::handler::set &>(subscriptionSet));
        }

        int engine::on(void) {
            if (singleton == nullptr) {
                singleton = new gardevoir::engine();

                queue = new gardevoir::queue();

                generator.command = new gardevoir::command::generator(singleton);
            }

            return declaration::fail;
        }

        int engine::run(void) {
            if (singleton != nullptr) {
                while (cancel == nullptr) {
                    queue->on();

                    generator.command->on();
                }

                cancel();

                singleton = allocator::del(singleton);
                queue = allocator::del(queue);
                generator.command = allocator::del(generator.command);

                cancel = nullptr;

                return declaration::success;
            }
            return declaration::fail;
        }
    }
}