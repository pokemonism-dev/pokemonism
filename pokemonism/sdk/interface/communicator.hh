/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_COMMUNICATOR_HH__
#define   __POKEMONISM_SDK_INTERFACE_COMMUNICATOR_HH__

#include <pokemonism.hh>

#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk::interface {

    class communicator : public synchronizable {
    public:     virtual int open(void) = 0;
    protected:  virtual long read(void) = 0;
    protected:  virtual long write(void) = 0;
    public:     virtual int close(void) = 0;
    public:     communicator(void) {}
    public:     ~communicator(void) override {}
    public:     communicator(const communicator & o) = delete;
    public:     communicator(communicator && o) noexcept = delete;
    public:     communicator & operator=(const communicator & o) = delete;
    public:     communicator & operator=(communicator && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_COMMUNICATOR_HH__