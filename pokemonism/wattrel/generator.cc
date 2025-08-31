/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "generator.hh"

#include "event.hh"
#include "subscription.hh"

namespace pokemonism {
    namespace wattrel {

        int generator::add(wattrel::subscription * o) {
            if (o != nullptr && o->container == nullptr) {
                collection::add(this, o);

                return o->on(wattrel::event::type::add);
            }

            return declaration::fail;
        }

        int generator::del(wattrel::subscription * o) {
            if (o != nullptr && o->container == this) {
                collection::del(this, o);

                const int ret = o->on(wattrel::event::type::del);

                if (o->properties & wattrel::subscription::property::release_on_del) queue.add(new subscription::releasor(o));

                return ret;
            }

            return declaration::fail;
        }

        void generator::clear(void) {
            while (head != nullptr) del(head);
        }




        // public:     virtual int reg(wattrel::subscription * o);
        // public:     virtual int del(wattrel::subscription * o);
        // public:     virtual void clear(void);
        // public:     generator(void);
        // public:     virtual ~generator(void);
    }
}