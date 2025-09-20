/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 18, 2025
 */

#ifndef   __POKEMONISM_SDK_SYNCHRONIZER_HH__
#define   __POKEMONISM_SDK_SYNCHRONIZER_HH__

#include <pokemonism/synchronizable.hh>

namespace pokemonism::sdk {

    template <class super = virtualable>
    class synchronizer : public synchronizable<super> {
    public:     struct guard;
    public:     int lock(void) override { return declaration::fail; }
    public:     int unlock(void) override { return declaration::fail; }
    public:     int wait(void) override { return declaration::fail; }
    public:     int wakeup(void) override { return declaration::fail; }
    public:     int wait(long second, long nano) override { return declaration::fail; }
    public:     int wakeup(bool all) override { return declaration::fail; }
    public:     inline synchronizer(void) {}
    public:     inline ~synchronizer(void) override {}
    public:     inline synchronizer(const synchronizer<super> & o) {}
    public:     inline synchronizer(synchronizer<super> && o) noexcept {}
    public:     inline synchronizer<super> & operator=(const synchronizer<super> & o){ return *this; }
    public:     inline synchronizer<super> & operator=(synchronizer<super> && o) noexcept{ return *this; }
    };

}

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/synchronizer/guard.hh>

#endif // __POKEMONISM_SDK_SYNCHRONIZER_HH__s