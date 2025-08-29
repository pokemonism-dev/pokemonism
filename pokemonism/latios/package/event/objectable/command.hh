/**
* @file        pokemonism/latios/package/event/objectable/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_EVENT_OBJECTABLE_COMMAND__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_EVENT_OBJECTABLE_COMMAND__HH__

#include <pokemonism/latios/package/event.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object>
            class event<object, pokemonism::command, pokemonism::command> : public eventable<object, objectable, generatable>::event {
            public:     int on(void) override {
                return fail;
            }
            public:     event(uint32 tag, eventable<object, objectable, generatable>::node * node);
            public:     event(void) = delete;
            };

            template <class object, class objectable, class generatable>
            event<object, objectable, generatable>::event(uint32 tag, typename eventable<object, objectable, generatable>::node * node) :
            eventable<object, objectable, generatable>::event(tag, node) {
            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_EVENT_OBJECTABLE_COMMAND__HH__
