/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMUNICATOR_HH__
#define   __POKEMONISM_SDK_COMMUNICATOR_HH__

#include <pokemonism.hh>

#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk::interface {

    class communicator : public synchronizable {
    protected:  int lock(void) noexcept override { return declaration::fail; }
    protected:  int unlock(void) noexcept override { return declaration::fail; }
    protected:  int wait(void) noexcept override { return declaration::fail; }
    protected:  int wakeup(void) noexcept override { return declaration::fail; }
    protected:  int wait(long second, long nano) noexcept override { return declaration::fail; }
    protected:  int wakeup(bool all) noexcept override { return declaration::fail; }
    public:     communicator(void) {}
    public:     ~communicator(void) override {}
    public:     communicator(const interface::communicator & o) = delete;
    public:     communicator(interface::communicator && o) noexcept = delete;
    public:     interface::communicator & operator=(const interface::communicator & o) = delete;
    public:     interface::communicator & operator=(interface::communicator && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COMMUNICATOR_HH__
