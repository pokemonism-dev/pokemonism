/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_DESCRIPTOR_HH__
#define   __POKEMONISM_SDK_GENERIC_DESCRIPTOR_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::generic {

    template <class descriptorable = interface::descriptor>
    class descriptor : public descriptorable {
    protected:  typedef descriptorable::type    type;
    protected:  inline explicit descriptor(generic::descriptor<descriptorable>::type value);
    public:     inline descriptor(void);
    public:     inline ~descriptor(void) override;
    public:     descriptor(const generic::descriptor<descriptorable> & o) = delete;
    public:     descriptor(generic::descriptor<descriptorable> && o) noexcept = delete;
    public:     generic::descriptor<descriptorable> & operator=(const generic::descriptor<descriptorable> & o) = delete;
    public:     generic::descriptor<descriptorable> & operator=(generic::descriptor<descriptorable> && o) noexcept = delete;
    };

    template <class descriptorable>
    inline descriptor<descriptorable>::descriptor(generic::descriptor<descriptorable>::type value) : descriptorable(value) {

    }

    template <class descriptorable>
    inline descriptor<descriptorable>::descriptor(void) {

    }

    template <class descriptorable>
    inline descriptor<descriptorable>::~descriptor(void) {

    }

}

#endif // __POKEMONISM_SDK_GENERIC_DESCRIPTOR_HH__