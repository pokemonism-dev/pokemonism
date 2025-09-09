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

#include <pokemonism/sdk/descriptorable.hh>
#include <pokemonism/sdk/interface/input.hh>
#include <pokemonism/sdk/interface/output.hh>
#include <pokemonism/sdk/interface/descriptor.hh>
#include <pokemonism/sdk/interface/input.hh>
#include <pokemonism/sdk/interface/output.hh>

namespace pokemonism::sdk::generic {

    template <class inputable>
    class descriptor : public inputable {
    public:     typedef inputable::type        type;
    public:     inline void clear(void) override;
    public:     inline void clean(void) override;
    public:     inline void reset(void) override;
    protected:  inline explicit descriptor(type value);
    public:     inline descriptor(void);
    public:     inline ~descriptor(void) override;
    public:     descriptor(const generic::descriptor<inputable> & o) = delete;
    public:     descriptor(generic::descriptor<inputable> && o) noexcept = delete;
    public:     generic::descriptor<inputable> & operator=(const generic::descriptor<inputable> & o) = delete;
    public:     generic::descriptor<inputable> & operator=(generic::descriptor<inputable> && o) noexcept = delete;
    };


    template <class inputable>
    inline void descriptor<inputable>::clear(void) {
        inputable::clear();
    }

    template <class inputable>
    inline void descriptor<inputable>::clean(void) {
        inputable::clean();
    }

    template <class inputable>
    inline void descriptor<inputable>::reset(void) {
        inputable::reset();
    }

    template <class inputable>
    inline descriptor<inputable>::descriptor(type value) : inputable(value) {

    }

    template <class inputable>
    inline descriptor<inputable>::descriptor(void) {

    }

    template <class inputable>
    inline descriptor<inputable>::~descriptor(void) {
    }

}

#endif // __POKEMONISM_SDK_GENERIC_DESCRIPTOR_HH__