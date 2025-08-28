/**
 * @file        pokemon/latios/internal/subscription.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include "subscription.hh"

#include "generator.hh"

#include "event.hh"
#include "queue.hh"

namespace pokemon { namespace latios { namespace internal {

    subscription * subscription::rem(subscription * o) {
        if (o != nullptr) {
            o->clear();
            if (o->container != nullptr) o->container->del(o);

            if (o->object != nullptr) {
                if (o->properties & subscription::property::release_object_on_rel) delete o->object;
                o->object = nullptr;
            }

            o->properties = none;
            o->status = none;
            o->func.bootstrap = nullptr;
            o->func.pack = nullptr;
        }

        return o;
    }

    subscription * subscription::rel(subscription * o) {
        if (o != nullptr) {
            rem(o);
            delete o;
        }
        return nullptr;
    }

    /** DEFAULT CLASS METHOD */
    subscription::~subscription(void) {
        if (container != nullptr) container->del(this);
        properties = none;
        status = none;
    }

    int subscription::on(uint32 type, internal::event * event, primitivable::object * result) {
        if (callbackSet) {
            if ((type = func.bootstrap != nullptr ? func.bootstrap(this, type, addressof(event), object, addressof(result)) : type) < max()) {
                const listener f = callbackSet[type];

                const int ret = f != nullptr ? f(object, type, event, result) : declaration::success;

                if (func.pack != nullptr) func.pack(this, type, event, object, result, ret);

                return ret;
            }
        }

        return declaration::success;
    }


    void subscription::cancel(void) {
        if (container != nullptr) container->del(this);
    }

    subscription::node * subscription::node::rem(subscription::node * o) {
        if (o != nullptr) {
            internal::event * event = o->event;
            internal::subscription * subscription = o->container;

            if (subscription != nullptr) subscription->del(o);

            if (event != nullptr) {
                if (internal::queue * queue = event->container; queue != nullptr) {
                    queue->del(event);

                    if (subscription != nullptr) subscription->on(event->type(), event, primitivable::object::gen(internal::event::fail));
                }
                event->node = nullptr;
                o->event = nullptr;
                delete event;
            }
        }

        return o;
    }



} } }
