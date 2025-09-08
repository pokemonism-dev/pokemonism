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

namespace pokemonism::sdk::generic {

    template <class inputable = pokemonism::sdk::interface::input, class outputable = pokemonism::sdk::interface::output>
    class descriptor : public inputable, public outputable, public pokemonism::sdk::interface::descriptor {
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
    public:     descriptor(const generic::descriptor<inputable, outputable> & o) = delete;
    public:     descriptor(generic::descriptor<inputable, outputable> && o) noexcept = delete;
    public:     generic::descriptor<inputable, outputable> & operator=(const generic::descriptor<inputable, outputable> & o) = delete;
    public:     generic::descriptor<inputable, outputable> & operator=(generic::descriptor<inputable, outputable> && o) noexcept = delete;
    };

    template <class inputable, class outputable>
    inline int descriptor<inputable, outputable>::valueGet(void) const {
        return value;
    }

    template <class inputable, class outputable>
    inline int descriptor<inputable, outputable>::close(void) {
        if (value > declaration::invalid) {
            ::close(value);

            value = declaration::invalid;

            stateOn(interface::descriptor::event::close, declaration::success);

            clear();
        }

        return declaration::success;
    }

    template <class inputable, class outputable>
    inline void descriptor<inputable, outputable>::clear(void) {
        inputable::clear();
        outputable::clear();
    }

    template <class inputable, class outputable>
    inline void descriptor<inputable, outputable>::clean(void) {
        inputable::clean();
        outputable::clean();
    }

    template <class inputable, class outputable>
    inline void descriptor<inputable, outputable>::reset(void) {
        inputable::reset();
        outputable::reset();
    }

    template <class inputable, class outputable>
    inline void descriptor<inputable, outputable>::stateOn(unsigned int state, long result, exception * e) {

    }

    template <class inputable, class outputable>
    inline descriptor<inputable, outputable>::descriptor(int value) : value(value) {

    }

    template <class inputable, class outputable>
    inline descriptor<inputable, outputable>::descriptor(void) : value(declaration::invalid) {

    }

    template <class inputable, class outputable>
    inline descriptor<inputable, outputable>::~descriptor(void) {
        descriptor::close();
    }

}

#endif // __POKEMONISM_SDK_GENERIC_DESCRIPTOR_HH__