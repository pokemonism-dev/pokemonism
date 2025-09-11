/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 04, 2025
 */

#ifndef   __POKEMONISM_SDK_SYNC_HH__
#define   __POKEMONISM_SDK_SYNC_HH__

#include <pokemonism.hh>
#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk {

    class sync : public synchronizable {
    public:     int lock(void) noexcept override { return declaration::fail; }
    public:     int unlock(void) noexcept override { return declaration::fail; }
    public:     int wait(void) noexcept override { return declaration::fail; }
    public:     int wakeup(void) noexcept override { return declaration::fail; }
    public:     int wait(long second, long nano) noexcept override { return declaration::fail; }
    public:     int wakeup(bool all) noexcept override { return declaration::fail; }
    public:     sync(void) {}
    public:     ~sync(void) override {}
    public:     sync(const sync & o) = delete;
    public:     sync(sync && o) noexcept = delete;
    public:     sync & operator=(const sync & o) = delete;
    public:     sync & operator=(sync && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_SYNC_HH__