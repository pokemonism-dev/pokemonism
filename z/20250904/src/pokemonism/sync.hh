/**
 * @file            pokemonism/sync.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SYNC_HH__
#define   __POKEMONISM_SYNC_HH__

#include <pokemonism.hh>

#include <pokemonism/interface/synchronizable.hh>

namespace pokemonism {

    class sync : public synchronizable {
    public:     int lock(void) override { return declaration::fail; }
    public:     int unlock(void) override { return declaration::fail; }
    public:     int wait(void) override { return declaration::fail; }
    public:     int wait(int64 second, int64 nano) override { return declaration::fail; }
    public:     int wakeup(void) override { return declaration::fail; }
    public:     int wakeup(bool all) override { return declaration::fail; }
    public:     sync(void) {}
    public:     ~sync(void) override {}
    public:     sync(const sync & o) = delete;
    public:     sync(sync && o) noexcept = delete;
    public:     sync & operator=(const sync & o) = delete;
    public:     sync & operator=(sync && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_SYNC_HH__
