/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_INPUT_HH__
#define   __POKEMONISM_SDK_INTERFACE_INPUT_HH__

#include <pokemonism/sdk/descriptorable.hh>
#include <pokemonism/sdk/interface/output.hh>

namespace pokemonism::sdk::interface {

    template <class outputable>
    class input : public outputable {
    public:     typedef outputable::type type;
    // protected:  inline long read(void) override;
    // protected:  inline long read(unsigned char * storage, unsigned long n) override;
    public:     inline explicit input(type value);
    public:     inline input(void);
    public:     inline ~input(void) override;
    public:     input(const interface::input<outputable> & o) = delete;
    public:     input(interface::input<outputable> && o) noexcept = delete;
    public:     interface::input<outputable> & operator=(const interface::input<outputable> & o) = delete;
    public:     interface::input<outputable> & operator=(interface::input<outputable> && o) noexcept = delete;
    };

    template <class outputable>
    inline input<outputable>::input(type value) : outputable(value) {

    }

    template <class outputable>
    inline input<outputable>::input(void) {

    }

    template <class outputable>
    inline input<outputable>::~input(void) {

    }

}

#endif // __POKEMONISM_SDK_INTERFACE_INPUT_HH__