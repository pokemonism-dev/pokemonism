/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 8, 2025
 */

#ifndef   __POKEMONISM_SDK_COLLECTION_INTERFACE_HH__
#define   __POKEMONISM_SDK_COLLECTION_INTERFACE_HH__

#include <pokemonism.hh>
#include <pokemonism/sdk/exception.hh>
#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk::collection {

    class interface : public synchronizable {
    public:     inline static unsigned long capacityCal(unsigned long n, unsigned long page);
    public:     inline int lock(void) override { return declaration::fail; }
    public:     inline int unlock(void) override { return declaration::fail; }
    public:     inline int wait(void) override { return declaration::fail; }
    public:     inline int wakeup(void) override { return declaration::fail; }
    public:     inline int wait(long second, long nano) override { return declaration::fail; }
    public:     inline int wakeup(bool all) override { return declaration::fail; }
    public:     virtual unsigned long sizeGet(void) = 0;
    public:     virtual unsigned long capacityGet(void) = 0;
    public:     virtual void clear(void) = 0;
    public:     virtual void clean(void) = 0;
    public:     virtual void reset(void) = 0;
    public:     inline interface(void) {}
    public:     inline ~interface(void) override {}
    public:     interface(const collection::interface & o) = delete;
    public:     interface(collection::interface && o) noexcept = delete;
    public:     collection::interface & operator=(const collection::interface & o) = delete;
    public:     collection::interface & operator=(collection::interface && o) noexcept = delete;
    };

    inline unsigned long interface::capacityCal(unsigned long n, unsigned long page) {
        pokemon_develop_check(page == 0, page = 1);

        return (n / page + (n % page == 0 ? 0 : 1)) * page;
    }

}

#endif // __POKEMONISM_SDK_COLLECTION_INTERFACE_HH__
