/**
 * @file        pokemon/latios/internal/engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include "engine.hh"

#include "command/generator.hh"

namespace pokemon { namespace latios { namespace internal {

    engine::engine(void) : queue(nullptr), cancel(nullptr), generator(nullptr) {

    }

    engine::~engine(void) {
        queue = allocator::del(queue);
        generator.command = allocator::del(generator.command);
        cancel = nullptr;
    }

    const char * engine::tag(void) const {
        return "internal";
    }

    external::command::subscription * engine::reg(latios::command * command, const uint32 properties, latios::command::event::listener (*on)[latios::command::event::max]) {
        critical_quick_throw_check(generator.command == nullptr, exceptional::nullpointer, return nullptr);

        printf("hello\n");
        internal::command::subscription * subscription = generator.command->subscriptionGen(command, properties, on);

        if (subscription != nullptr) generator.command->reg(subscription);

        return subscription;
    }

    void engine::dispatch(internal::event * o) {
        critical_quick_throw_check(queue == nullptr, exceptional::nullpointer, do {
            if (o != nullptr) delete o;
        } while (0));

        if (o != nullptr) queue->push(o);
    }

    void engine::off(void (*func)(external::engine &)) {
        cancel = func;
    }

    int engine::run(void) {
        lock();
        while (cancel == nullptr) {
            unlock();
            queue->on();

            generator.command->on();
            lock();
        }
        unlock();

        cancel(*this);

        return declaration::success;
    }

    external::engine & engine::on(void) {
        if (queue == nullptr) queue = new internal::queue();
        if (generator.command == nullptr) generator.command = new command::generator(this);
        return *this;
    }


} } }
