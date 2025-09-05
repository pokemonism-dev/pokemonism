/**
 * @file            pokemonism/item.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 5, 2025
 */

#ifndef   __POKEMONISM_ITEM_HH__
#define   __POKEMONISM_ITEM_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class item {
    public:     item(void) {}
    public:     virtual ~item(void) {}
    public:     item(const item & o) = delete;
    public:     item(item && o) noexcept = delete;
    public:     item & operator=(const item & o) = delete;
    public:     item & operator=(item && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_ITEM_HH__