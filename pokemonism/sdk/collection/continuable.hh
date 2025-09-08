/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COLLECTION_CONTINUABLE_HH__
#define   __POKEMONISM_SDK_COLLECTION_CONTINUABLE_HH__

#include <pokemonism/sdk/collection/sequenceable.hh>

namespace pokemonism::sdk::collection {

    template <typename elementable>
    class continuable : public collection::sequenceable<elementable> {
    public:     constexpr static unsigned long page = 8;
    public:     virtual unsigned long set(void) = 0;
    public:     virtual unsigned long set(const elementable & item, unsigned long n) = 0;
    public:     virtual unsigned long set(const elementable * source, unsigned long sourceLen) = 0;
    public:     virtual unsigned long cat(const elementable & item, unsigned long n) = 0;
    public:     virtual unsigned long cat(const elementable * source, unsigned long sourceLen) = 0;
    public:     virtual unsigned long cut(unsigned long offset) = 0;
    public:     virtual unsigned long pop(unsigned long length) = 0;
    protected:  continuable(void) {}
    protected:  ~continuable(void) override {}
    public:     continuable(const collection::continuable<elementable> & o) = delete;
    public:     continuable(collection::continuable<elementable> && o) noexcept = delete;
    public:     collection::continuable<elementable> & operator=(const collection::continuable<elementable> & o) = delete;
    public:     collection::continuable<elementable> & operator=(collection::continuable<elementable> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COLLECTION_CONTINUABLE_HH__