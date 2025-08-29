/**
 * @file        pokemonism/latios/package/processor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_PROCESSOR__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_PROCESSOR__HH__

#include <pokemonism/latios/general/engine.hh>
#include <pokemonism/latios/general/processor.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            class processor : public general::processor {
            public:     template <class subscription = general::subscription, class event> static int on(subscription * o, uint32 type, primitivable::object ** result, event * e) {
                            throw pokemonism::exception();
                        }
            public:     processor(void) {}
            public:     ~processor(void) {}
            public:     processor(const processor & o) = delete;
            public:     processor(processor && o) noexcept = delete;
            public:     processor & operator=(const processor & o) = delete;
            public:     processor & operator=(processor && o) noexcept = delete;
            };

            // template <class subscription, class event>
            // int (*processor<subscription, event>::on)(subscription *, uint32, event *) = nullptr;

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_PROCESSOR__HH__
