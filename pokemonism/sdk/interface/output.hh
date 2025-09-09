/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_OUTPUT_HH__
#define   __POKEMONISM_SDK_INTERFACE_OUTPUT_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    template <class descriptorable = interface::descriptor>
    class output : public descriptorable {
    public:     typedef descriptorable::type type;
    public:     inline explicit output(type value);
    public:     inline output(void);
    public:     inline virtual ~output(void) override;
    public:     output(const interface::output<descriptorable> & o) = delete;
    public:     output(interface::output<descriptorable> && o) noexcept = delete;
    public:     interface::output<descriptorable> & operator=(const interface::output<descriptorable> & o) = delete;
    public:     interface::output<descriptorable> & operator=(interface::output<descriptorable> && o) noexcept = delete;
    };

    template <class descriptorable>
    inline output<descriptorable>::output(type value) : descriptorable(value) {

    }

    template <class descriptorable>
    inline output<descriptorable>::output(void) {

    }

    template <class descriptorable>
    inline output<descriptorable>::~output(void) {

    }

}

#endif // __POKEMONISM_SDK_INTERFACE_OUTPUT_HH__