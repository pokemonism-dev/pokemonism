/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_DESCRIPTOR_HH__
#define   __POKEMONISM_SDK_GENERIC_DESCRIPTOR_HH__

#include <unistd.h>

#include <pokemonism/sdk/interface/input.hh>
#include <pokemonism/sdk/interface/output.hh>
#include <pokemonism/sdk/interface/descriptor.hh>
#include <pokemonism/sdk/interface/input.hh>
#include <pokemonism/sdk/interface/output.hh>

namespace pokemonism::sdk::generic {

    template <class outputable = pokemonism::sdk::interface::output, class inputable = pokemonism::sdk::interface::input<outputable>>
    class descriptor : public inputable {
    protected:  int value;
    protected:  inline int valueGet(void) const;
    public:     inline int close(void) override;
    public:     inline void clear(void) override;
    public:     inline void clean(void) override;
    public:     inline void reset(void) override;
    public:     inline void stateOn(unsigned int state, long result, exception * e = nullptr) override;
    protected:  inline  explicit descriptor(int value);
    public:     inline descriptor(void);
    public:     inline ~descriptor(void) override;
    public:     descriptor(const generic::descriptor<outputable, inputable> & o) = delete;
    public:     descriptor(generic::descriptor<outputable, inputable> && o) noexcept = delete;
    public:     generic::descriptor<outputable, inputable> & operator=(const generic::descriptor<outputable, inputable> & o) = delete;
    public:     generic::descriptor<outputable, inputable> & operator=(generic::descriptor<outputable, inputable> && o) noexcept = delete;
    };

    template <class outputable, class inputable>
    inline int descriptor<outputable, inputable>::valueGet(void) const {
        return value;
    }

    template <class outputable, class inputable>
    inline int descriptor<outputable, inputable>::close(void) {
        if (value > declaration::invalid) {
            ::close(value);

            value = declaration::invalid;

            stateOn(interface::descriptor::event::close, declaration::success);

            clear();
        }

        return declaration::success;
    }

    template <class outputable, class inputable>
    inline void descriptor<outputable, inputable>::clear(void) {
        inputable::clear();
        outputable::clear();
    }

    template <class outputable, class inputable>
    inline void descriptor<outputable, inputable>::clean(void) {
        inputable::clean();
        outputable::clean();
    }

    template <class outputable, class inputable>
    inline void descriptor<outputable, inputable>::reset(void) {
        inputable::reset();
        outputable::reset();
    }

    template <class outputable, class inputable>
    inline void descriptor<outputable, inputable>::stateOn(unsigned int state, long result, exception * e) {

    }

    template <class outputable, class inputable>
    inline descriptor<outputable, inputable>::descriptor(int value) : value(value) {

    }

    template <class outputable, class inputable>
    inline descriptor<outputable, inputable>::descriptor(void) : value(declaration::invalid) {

    }

    template <class outputable, class inputable>
    inline descriptor<outputable, inputable>::~descriptor(void) {
        descriptor::close();
    }

}

#endif // __POKEMONISM_SDK_GENERIC_DESCRIPTOR_HH__