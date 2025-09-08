/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_HH__
#define   __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_HH__

#include <pokemonism.hh>
#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk::interface {

    class descriptor : public synchronizable {
    protected:  int lock(void) noexcept override { return declaration::fail; }
    protected:  int unlock(void) noexcept override { return declaration::fail; }
    protected:  int wait(void) noexcept override { return declaration::fail; }
    protected:  int wakeup(void) noexcept override { return declaration::fail; }
    protected:  int wait(long second, long nano) noexcept override { return declaration::fail; }
    protected:  int wakeup(bool all) noexcept override { return declaration::fail; }
    public:     virtual int open(void) = 0;
    public:     virtual int close(void) = 0;
    protected:  virtual long read(void) = 0;
    protected:  virtual long write(void) = 0;
    public:     virtual unsigned int check(unsigned int state) const = 0;
    public:     descriptor(void) {}
    public:     ~descriptor(void) override {}
    public:     descriptor(const interface::descriptor & o) = delete;
    public:     descriptor(interface::descriptor && o) noexcept = delete;
    public:     interface::descriptor & operator=(const interface::descriptor & o) = delete;
    public:     interface::descriptor & operator=(interface::descriptor && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_HH__